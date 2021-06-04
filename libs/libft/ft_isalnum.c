#include "libft.h"

/*
**	@brief	tests for any character for which is alphabet or number
**	
**	@param	c	character
**	@return	int	0 if tests false, else 1
*/
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
