#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_param	p;

	inicialize_param(argc, argv, envp, &p);
	get_commands(argc, argv, &p);
	get_paths(&p);
	pipex(&p);
}

void	pipex(t_param *p)
{
	char	*cmnd;

	inicialize_in(p);
	inicialize_out(p);

	cmnd = p->cmnds[p->ind][0];
	while (get_next_path(p, cmnd, p->ind))
	{
		execve(p->cmnds[p->ind][0], p->cmnds[p->ind], p->envp);
		if (errno != 2)
			break ;
	}
	ft_raise_error(NULL);
}

/*
**	@brief	replaces the standart output of the executable program 
**			to a file or pipe, as needed.
**	
**	@param	p	pointer to patams
*/
void	inicialize_out(t_param *p)
{
	
	if (p->total_pipes && p->total_pipes != p->ind + 1) // запустить только если это не папка всех папок (для него есть прошлый пайп)
	{
		if (dup2(p->old_fds_1, STDOUT) < 0) // выход текущей команды заворачиваем со стандартного выхода на прошлый пайп
			ft_raise_error(NULL);
		close(p->old_fds_1);
	}
	else if (p->outfile) // для папки меняем выход, если был выходной файл
		if (dup2(my_open(p, p->outfile, false), STDOUT) < 0)
			ft_raise_error(NULL);
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
	if (p->ind) // есть потомки
	{
		close(p->fds[0]);
		p->old_fds_1 = p->fds[1];
		if (pipe(p->fds) < 0)
			ft_raise_error("NULL");
		p->pid = fork();
		if (p->pid)  // если это папка для текущей пары процессов - то ждем отпрыска
		{
			wait(0);
			if (dup2(p->fds[0], STDIN) < 0) // и заворачиваем вход со стандартного на результаты работы отпрыска
				ft_raise_error(NULL);
			close(p->fds[0]);
			close(p->fds[1]);
		}
		else	// это отпрыск. но в следующей итерации ему быть папкой
		{
			p->ind--;
			return (pipex(p));
		}
			
	}
	else if (p->infile) // меняем вход если был входной файл
	{
		// sleep(20);
		if (dup2(my_open(p, p->infile, true), STDIN) < 0)
			ft_raise_error(NULL);
	}
}
