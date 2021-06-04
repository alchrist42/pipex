#include "libft.h"

/*
**	@brief	locates the first occurrence of c in the string, search max n bytes
**	
**	@param	s		pointer to string
**	@param	c		character
**	@param	n		max distation search in bytes
**	@return	void*	pointer to location c, or NULL if c not found
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
