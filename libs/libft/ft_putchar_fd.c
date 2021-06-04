#include "libft.h"

/*
**	@brief	outputs the character ’c’ to the given file descriptor.
**			May write to standart out
**	
**	@param	c		character
**	@param	fd		file descriptor
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
