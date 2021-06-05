#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_param	p;

	inicialize_param(argc, argv, envp, &p);
	parsing(argc, argv, &p);
	if (pipe(p.fds) < 0)
		ft_raise_error("NULL");
	p.pid = fork();
	if (p.pid)
		run_father(&p);
	else
		run_child(&p);
	ft_raise_error(NULL);
}

void	run_father(t_param *p)
{
	char	*cmnd;

	wait(0);
	if (dup2(p->fds[0], STDIN) < 0)
		ft_raise_error(NULL);
	if (dup2(p->outfile, STDOUT) < 0)
		ft_raise_error(NULL);
	close(p->fds[0]);
	close(p->fds[1]);
	cmnd = p->cmnds[1][0];
	while (get_next_path(p, cmnd, 1))
	{
		execve(p->cmnds[1][0], p->cmnds[1], p->envp);
		if (errno != 2)
			break ;
	}
}

void	run_child(t_param *p)
{
	char	*cmnd;

	if (dup2(p->fds[1], STDOUT) < 0)
		ft_raise_error(NULL);
	if (dup2(p->infile, STDIN) < 0)
		ft_raise_error(NULL);
	close(p->fds[0]);
	close(p->fds[1]);
	cmnd = p->cmnds[0][0];
	while (get_next_path(p, cmnd, 0))
	{
		execve(p->cmnds[0][0], p->cmnds[0], p->envp);
		if (errno != 2)
			break ;
	}
}
