#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include <sys/errno.h>

# define DEBUG 1

# define STDIN 0
# define STDOUT 1

extern int errno;

typedef struct s_param
{
	int		infile;
	int		outfile;
	int		fds[2];
	pid_t	pid;
	char	**argv;
	char	**envp;
	char	***cmnds;

}	t_param;

// pipex
int	main(int argc, char **argv, char **envp);
void	parsing(int argc, char **argv, t_param *p);

// raise_error
void	ft_raise_error(char *s);


#endif