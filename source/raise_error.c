#include "pipex.h"

/*
**	@brief	raises error message and exit from program
**	
**	@param	s	pointer to string with error message
*/
void	ft_raise_error(char *msg, char *errno_msg)
{
	// ft_putstr_fd("Error\n", 2);
	if (msg)
		ft_putstr_fd(msg, 2);
	else
		perror(errno_msg);
	if (errno)
		exit (errno);
	else
		exit(1);
}

int	ft_is_path(char *s)
{
	while(*s && !ft_isalnum(*s))
		if (*s++ == '/')
			return (1);
	return (0);
}
