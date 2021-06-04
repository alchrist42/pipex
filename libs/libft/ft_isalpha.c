#include "libft.h"

/*
**	@brief	checks a character for alphabeticality
**	
**	@param	c		character
**	@return	int		0 if test false, else 1
*/
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
