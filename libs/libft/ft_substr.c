#include "libft.h"

/*
**	@brief	allocates and returns a substring from the string.
**			The substring begins at index ’start’ and is of maximum size ’len’
**	
**	@param	s		pointer to string
**	@param	start	index start of substring
**	@param	len		index end of substring
**	@return	char*	pointer to new string or NULL if allocation fail
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;

	s2 = (char *)malloc((len + 1) * sizeof(*s2));
	if (!s2)
		return (NULL);
	s2[0] = 0;
	if (ft_strlen(s) < start)
		return (s2);
	ft_strlcpy(s2, s + start, (len + 1));
	return (s2);
}
