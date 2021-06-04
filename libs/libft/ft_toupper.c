#include "libft.h"

/*
**	@brief		convert char to uppercase if it's lowercase
**	
**	@param	c		character
**	@return	int		character
*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c += 'A' - 'a';
	return (c);
}
