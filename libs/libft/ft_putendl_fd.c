#include "libft.h"

/*
**	@brief	Outputs the string ’s’ to the given file descriptor, 
**			followed by a newline.
**	
**	@param	s		pointer to string
**	@param	fd		file descriptor
*/
void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
