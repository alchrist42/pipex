#include "pipex.h"

/*
**	@brief	raises error message and exit from program
**	
**	@param	s	pointer to string with error message
*/
void	ft_raise_error(char *s)
{
	ft_putstr_fd("Error\n", 2);
	if (s)
		ft_putstr_fd(s, 2);
	else
		perror(NULL);
	if (errno)
		exit (errno);
	else
		exit(errno);
}
