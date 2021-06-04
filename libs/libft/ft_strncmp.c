#include "libft.h"

/*
**	@brief	lexicographically compare two strings. Not more n characters
**	
**	@param	s1		pointer to string
**	@param	s2		pointer to string
**	@param	n		count bytes
**	@return	int	zero if strings are identical, 
**				else difference between two elements (unsinged char)
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && i + 1 < n && s1[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
