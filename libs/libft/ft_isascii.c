#include "libft.h"

/*
**	@brief	checks a character is betwen 0 and 127
**	
**	@param	c		character
**	@return	int		0 if test false, else 1
*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
