#include "libft.h"

/*
**	@brief	convert char to lowercase if it's uppercase
**	
**	@param	c		character
**	@return	int		character
*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}
