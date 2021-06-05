#include "pipex.h"

void	inicialize_param(int argc, char **argv, char **envp, t_param *p)
{
	p->argv = argv;
	p->envp = envp;
	p->cmnds = malloc(sizeof(*p->cmnds) * (argc - 2));
	if (!p->cmnds)
		ft_raise_error(NULL);
	p->cmnds[argc - 3] = NULL;
}

void	parsing(int argc, char **argv, t_param *p)
{
	int	i;

	if (argc != 5)
		ft_raise_error("Usage : ./pipex infile cmd1 cmd2 outfile\n");
	p->infile = open(argv[1], O_RDONLY);
	if (p->infile < 0)
		ft_raise_error(NULL);
	p->outfile = open(argv[--argc], O_RDWR | O_CREAT | O_TRUNC, 00700);
	if (p->outfile < 0)
		ft_raise_error(NULL);
	get_paths(p);
	i = 1;
	while (++i < argc)
	{
		p->cmnds[i - 2] = ft_split_set(argv[i], " ");
		if (!p->cmnds[i - 2])
			ft_raise_error(NULL);
	}
}

void	get_paths(t_param *p)
{
	int		i;

	i = -1;
	while (p->envp[++i])
	{
		if (!ft_strncmp(p->envp[i], "PATH=", 5))
		{
			p->paths = ft_split(p->envp[i] + 5, ':');
			if (!p->paths)
				ft_raise_error(NULL);
			p->paths_len = ft_split_len(p->paths);
			return ;
		}
	}
	p->paths_len = 0;
}

int	get_next_path(t_param *p, char *cmnd, int i)
{
	static int	z;
	char		*temp;

	if (z > 1)
		free(p->cmnds[i][0]);
	if (z > p->paths_len)
	{
		z = 0;
		p->cmnds[i][0] = cmnd;
		return (0);
	}
	if (z)
	{
		temp = ft_strjoin(p->paths[z - 1], "/");
		p->cmnds[i][0] = ft_strjoin(temp, cmnd);
		if (!temp || !p->cmnds[i][0])
			ft_raise_error("NULL");
		free(temp);
	}
	z++;
	return (1);
}
