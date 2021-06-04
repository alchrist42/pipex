#include "libft.h"

/*
**	@brief	copies n bytes from memory area src to memory area dst.
**			If dst and src overlap, behavior is undefined.
**	
**	@param	dst		pointer to dist
**	@param	src		pointer to source
**	@param	n		count bytes for copy
**	@return	void*	original pointer to dist
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}	
	return (dst);
}
