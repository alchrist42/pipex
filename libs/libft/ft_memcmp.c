#include "libft.h"

/*
**	@brief	compares two strings. compare maximum n bytes
**	
**	@param	s1		pointer to string
**	@param	s2		pointer to string
**	@param	n		maximum lenght of compare
**	@return	int	zero if strings are equal, else difference between different bytes
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
