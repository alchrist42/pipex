#include "libft.h"

/*
**	@brief	allocates memory and contactination two strings
**	
**	@param	s1		pointer to string
**	@param	s2		pointer to string
**	@return	char*	pointer to new result string or NULL
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(*s3));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, len_s1 + 1);
	ft_strlcpy(&s3[len_s1], s2, len_s2 + 1);
	return (s3);
}
