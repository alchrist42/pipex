#include "pipex.h"

#define BUFFER_SIZE 1048576

int	ne_gnl(int fd, char **line, const char *keyword)
{
	int	result;
	int	i;

	i = 0;
	*line = malloc(BUFFER_SIZE);
	if (!line)
		return (-1);
	while (i < BUFFER_SIZE - 1
		&& (result = read(fd, *line + i, 1)))
	{
		if (result == -1)
			return (-1);
		if ((*line)[i] == '\n')
			break ;
		i++;
	}
	(*line)[i] = 0;
	if (ft_strncmp(*line, keyword, ft_strlen(keyword) + 1))
		return (1);
	return (0);
}

void	left_double_arrow(t_param *p)
{
	int	fd[2];

	if (pipe(fd) < 0)
		ft_raise_error(NULL);
	p->pid = fork();
	if (p->pid)
	{
		wait(0);
		if (dup2(fd[0], STDIN) < 0)
			ft_raise_error(NULL);
		close(fd[0]);
		close(fd[1]);
	}
	else
		child_left_double_arrow(p, fd);
}

void	child_left_double_arrow(t_param *p, int *fd)
{
	char	*line;
	int		res;

	res = 1;
	while (res)
	{
		ft_putstr_fd("heredoc> ", 1);
		res = ne_gnl(0, &line, p->infile);
		if (res < 0)
			ft_raise_error(NULL);
		if (res)
			ft_putendl_fd(line, fd[1]);
		free(line);
	}
	p->infile = NULL;
	close(fd[0]);
	close(fd[1]);
	exit(0);
}
