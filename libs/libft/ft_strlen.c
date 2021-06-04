#include "libft.h"

/*
**	@brief	return lenght null terminated string
**	
**	@param	s		pointer to string
**	@return	size_t	lenght string
*/
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
