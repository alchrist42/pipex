#include "libft.h"

/*
**	@brief	finds last element of the list
**	
**	@param	lst		pointer to begin of the list
**	@return	t_list*	pointer to the end of the list
*/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
