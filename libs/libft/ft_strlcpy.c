#include "libft.h"

/*
**	@brief	copy source string to dest string, not more than dstsize - 1.
**			than null terminate dest.
**	
**	@param	dst		pointer to string
**	@param	src		pointer to string
**	@param	dstsize		count bytes to copy + 1 for null terminate
**	@return	size_t	lenght src string
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		if (dst && i + 1 < dstsize)
			dst[i] = src[i];
		i++;
	}
	if (dstsize && dst)
	{
		if (dstsize - 1 < i)
			dst[dstsize - 1] = 0;
		else
			dst[i] = 0;
	}
	return (i);
}
