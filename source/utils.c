#include "pipex.h"

void	inicialize_param(int argc, char **argv, char **envp, t_param *p)
{
	if (argc != 5)
		ft_raise_error("Usage : ./pipex infile cmd1 ... cmdn outfile\n", NULL);
	p->infile = argv[1];
	p->outfile = argv[argc - 1];
	p->argv = argv;
	p->envp = envp;
	p->cnt_cmnds = argc - 3;
	p->ind = p->cnt_cmnds - 1;
	p->cmnds = malloc(sizeof(*p->cmnds) * (argc - 2));
	if (!p->cmnds)
		ft_raise_error(NULL, NULL);
	p->cmnds[p->cnt_cmnds] = NULL;
}

void	get_commands(int argc, char **argv, t_param *p)
{
	int	i;

	i = 1;
	while (++i < argc - 1)
	{
		p->cmnds[i - 2] = ft_split_set(argv[i], " ");
		if (!p->cmnds[i - 2])
			ft_raise_error(NULL, NULL);
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
				ft_raise_error(NULL, NULL);
			p->paths_len = ft_split_len(p->paths);
			return ;
		}
	}
	p->paths_len = 0;
}

/*
**	@brief	Generator for getting the next path objects.
** 			Path consist name of the comand and slice path from PATH
**	
**	@param	p		pointer to parametrs structure
**	@param	cmnd	name of the comand
**	@param	i		command index
**	@return	int		1 if next path available, else 0
*/
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
	if (!z && !ft_is_path(cmnd))
		z++;
	if (z)
	{
		temp = ft_strjoin(p->paths[z - 1], "/");
		p->cmnds[i][0] = ft_strjoin(temp, cmnd);
		if (!temp || !p->cmnds[i][0])
			ft_raise_error(NULL, NULL);
		free(temp);
	}
	z++;
	return (1);
}

/*
**	@brief	open input or output files. create output file if not exist
**	
**	@param	fname		string with file name
**	@param	is_infile	is input file
**	@return	int			file descriptor
*/
int	my_open(t_param *p, char *fname, int mode)
{
	int	fd;

	if (mode == 1)
	{
		fd = open(fname, O_RDONLY);
		p->infile = NULL;
	}
	else if (mode == 2)
	{
		fd = open(fname, O_RDWR | O_CREAT | O_TRUNC, 00774);
		p->outfile = NULL;
	}
	else if (mode == 3)
	{
		fd = open(fname, O_WRONLY | O_APPEND | O_CREAT, 00774);
		p->outfile = NULL;
	}
	else
		fd = -1;
	if (fd < 0)
		ft_raise_error(NULL, fname);
	return (fd);
}
