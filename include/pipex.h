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

# define STDIN 0
# define STDOUT 1

typedef struct s_param
{
	char	*infile;
	char	*outfile;
	char	**paths;
	int		paths_len;
	int		fds[2];
	int		old_fds_1;
	pid_t	pid;
	char	**argv;
	char	**envp;
	int		total_pipes;
	int		ind;
	char	***cmnds;
}	t_param;

// pipex
int		main(int argc, char **argv, char **envp);
void	pipex(t_param *p);
void	inicialize_in(t_param *p);
void	inicialize_out(t_param *p);

// utils.c
void	inicialize_param(int argc, char **argv, char **envp, t_param *p);
void	get_commands(int argc, char **argv, t_param *p);
void	get_paths(t_param *p);
int		get_next_path(t_param *p, char *cmnd, int i);
int		my_open(t_param *p, char *fname, bool is_infile);

// raise_error
void	ft_raise_error(char *s);

#endif