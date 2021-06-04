#include "libft.h"

/*
**	@brief	deletes and free one element of the list
**	
**	@param	lst		pointer to element of the list
*/
void	ft_lstdelone(t_list *lst)
{
	if (lst)
	{
		free(lst);
	}
}
