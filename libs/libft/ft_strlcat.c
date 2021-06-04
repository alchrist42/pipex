#include "libft.h"

/*
**	@brief	adds string src to string dst, 
*			where finish string lenght no more than dstsize
**	
**	@param	dst			pointer to string
**	@param	src			pointer to string
**	@param	dstsize		length finish string  (with '\0')
**	@return	size_t		expected length of the resulting string (dst + src)
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	j = 0;
	while (src[j])
	{
		if (j + i + 1 < dstsize)
			dst[i + j] = src[j];
		j++;
	}
	if (dstsize > i)
	{
		if (dstsize - 1 < i + j)
			dst[dstsize - 1] = 0;
		else
			dst[i + j] = 0;
	}
	return (i + j);
}
