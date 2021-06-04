#include "libft.h"

/*
**	@brief	allocations memory like malloc, but uses count object multiply by 
**			size objects and then fills space zeros
**	
**	@param	count		count objects
**	@param	size		size one object in bytes
**	@return	void*	pointer to allocation memory or NULL if allocation fail
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}
