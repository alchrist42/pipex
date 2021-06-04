#include "libft.h"

/*
**	@brief	checks a character is number between '0' and '9'
**	
**	@param	c		character
**	@return	int		0 if tests false, else 1
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
