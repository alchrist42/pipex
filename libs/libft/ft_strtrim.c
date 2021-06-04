#include "libft.h"

/*
**	@brief	checks that a character is a delimiter
**	
**	@param	ch		character
**	@param	set		pointer to string of delimiters
**	@return	int	zero if check fail, else 1
*/
static int	is_trimmed(char ch, char const *set)
{
	while (*set)
		if (ch == *set++)
			return (1);
	return (0);
}

/*
**	@brief	allocates and returns a copy of string 
**			with the characters specified in delimiters removed
**			from the beginning and the end of the string.
**	
**	@param	s1		pointer to string
**	@param	set		pointer to string of delimiters
**	@return	char*	pointer to new truncated string or NULL if allocation fail
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*s2;

	while (*s1 && is_trimmed(*s1, set))
		s1++;
	i = 0;
	while (s1[i])
		i++;
	while (i >= 0 && (is_trimmed(s1[i], set) || !s1[i]))
		i--;
	i += 2;
	s2 = (char *)malloc(i * sizeof(*s2));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, i);
	return (s2);
}
