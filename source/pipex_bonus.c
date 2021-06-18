#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_param	p;

	inicialize_param(argc, argv, envp, &p);
	get_commands(argc, argv, &p);
	get_paths(&p);
	pipex(&p);
}

/*
**	@brief	recursive runs all commands separated by pipe
**	
**	@param	p	pointer to params
*/
void	pipex(t_param *p)
{
	inicialize_in(p);
	inicialize_out(p);
	run_command(p);
}

/*
**	@brief	changes the standard input of the executable program 
**			to a file or previous pipe results, as needed.
** 			Runs the new iteration for next pipe.
**	
**	@param	p	pointer to params
*/
void	inicialize_in(t_param *p)
{
	if (p->ind > 0)
	{
		close(p->fds[0]);
		p->old_fds_1 = p->fds[1];
		if (pipe(p->fds) < 0)
			ft_raise_error(NULL, NULL);
		p->pid = fork();
		if (p->pid)
		{
			wait(0);
			if (dup2(p->fds[0], STDIN) < 0)
				ft_raise_error(NULL, NULL);
			close(p->fds[0]);
			close(p->fds[1]);
		}
		else if (p->ind-- > -2)
			return (pipex(p));
	}
	else if (p->stop_word)
		left_double_arrow(p);
	else if (p->infile)
		if (dup2(my_open(p, p->infile, L_ARR), STDIN) < 0)
			ft_raise_error(NULL, NULL);
}

/*
**	@brief	replaces the standart output of the executable program 
**			to a file or pipe, as needed.
**	
**	@param	p	pointer to patams
*/
void	inicialize_out(t_param *p)
{
	if (p->cnt_cmnds != (p->ind + 1))
	{
		if (p->ind)
			p->fds[1] = p->old_fds_1;
		if (dup2(p->fds[1], STDOUT) < 0)
			ft_raise_error(NULL, NULL);
		close(p->fds[1]);
	}
	else if (p->outfile && p->stop_word)
	{
		if (dup2(my_open(p, p->outfile, R_D_ARR), STDOUT) < 0)
			ft_raise_error(NULL, NULL);
	}
	else if (p->outfile)
	{
		if (dup2(my_open(p, p->outfile, R_ARR), STDOUT) < 0)
			ft_raise_error(NULL, NULL);
	}
}

/*
**	@brief	searches and runs the command 
**			by its name and paths from enviroment
**	
**	@param	p	pointer to patams
*/
void	run_command(t_param *p)
{
	char	*cmnd;

	cmnd = p->cmnds[p->ind][0];
	while (get_next_path(p, cmnd, p->ind))
	{
		if (!access(p->cmnds[p->ind][0], F_OK))
		{
			if (!access(p->cmnds[p->ind][0], X_OK))
				execve(p->cmnds[p->ind][0], p->cmnds[p->ind], p->envp);
			break ;
		}
	}
	ft_raise_error(ft_strjoin("Command not found: ", cmnd), NULL);
}
