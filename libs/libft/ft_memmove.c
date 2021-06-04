#include "libft.h"

/*
**	@brief	copies n bytes from memory area src to memory area dst.
**			The two strings may overlap.
**	
**	@param	dst		pointer to dist
**	@param	src		pointer to source
**	@param	len		count bytes for copy
**	@return	void*	original pointer to dist
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}	
	}
	else
	{
		while (len)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}	
	}
	return ((void *)dst);
}
