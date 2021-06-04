#include "libft.h"

/*
**	@brief	writes n zeroed bytes to the string s
**	
**	@param	s		pointer  to string s
**	@param	n		lenght zeroes
*/
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*buf;

	buf = (unsigned char *)s;
	i = 0;
	while (i < n)
		buf[i++] = 0;
}
