#include "libft.h"

/*
**	@brief	locates the first occurrence of c in the string s
**	
**	@param	s		pointer to string
**	@param	c		character to search
**	@return	char*	pointer to the found position c or NULL
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s != c && *s)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
