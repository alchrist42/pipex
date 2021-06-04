#include "libft.h"

/*
**	@brief	create copy of string,
**			and apply function f to each element new string
**	
**	@param	s		pointer to string
**	@param	f		function, return char
**	@return	char*	new string
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	size_t	i;

	new_s = ft_strdup(s);
	if (!new_s)
		return (NULL);
	i = 0;
	while (new_s[i])
	{
		new_s[i] = f(i, new_s[i]);
		i++;
	}
	return (new_s);
}
