#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	// pid_t		pid;
	t_param 	p;
	
	p.argv = argv;
	p.envp = envp;
	p.cmnds = malloc(sizeof(*p.cmnds) * (argc - 2));
	if (!p.cmnds)
		ft_raise_error(NULL);
	p.cmnds[argc - 3] = NULL;
	ft_putendl_fd(argv[1], 1);
	ft_putendl_fd(argv[2], 1);
	parsing(argc, argv, &p);
	execve(p.cmnds[0][0], p.cmnds[0], 0);
	ft_raise_error(NULL);
	
}

void	parsing(int argc, char **argv, t_param *p)
{
	char	*cmnd;
	int		i;

	if (argc != 5)
		ft_raise_error("Usage : ./pipex infile cmd1 cmd2 outfile\n");
	p->infile = open(argv[1], O_RDONLY);
	if (p->infile < 0)
		ft_raise_error(NULL);
	p->outfile = open(argv[--argc], O_WRONLY);
	if (p->outfile < 0)
		ft_raise_error(NULL);
	i = 1;
	while (++i < argc)
	{
		p->cmnds[i - 2] = ft_split_set(argv[i], " ");
		if (!p->cmnds[i - 2])
			ft_raise_error(NULL);
		cmnd = p->cmnds[i - 2][0];
		if (ft_strncmp(cmnd, "./", 2) && ft_strncmp(cmnd, "/", 1))
		{
			p->cmnds[i - 2][0] = ft_strjoin("/bin/", cmnd);
			free(cmnd);
		}
		ft_putstr_fd("new file to run name: ", 1); // to del
		ft_putendl_fd(p->cmnds[i - 2][0], 1);
	}
}