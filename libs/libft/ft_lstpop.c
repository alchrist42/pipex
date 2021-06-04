#include "libft.h"

/*
**	@brief	pops first or last element from the list
**	
**	@param	lst		pointer  to poiner to list
**	@param	first	first or last element?
**	@return	t_list*	pointer to element
*/
t_list	*ft_lstpop(t_list **lst, bool first)
{
	t_list	*elem;
	t_list	*curr;

	if (first)
	{
		elem = *lst;
		*lst = elem->next;
		elem->next = NULL;
	}
	else if (!(*lst)->next)
	{
		elem = (*lst);
		*lst = NULL;
	}
	else
	{
		curr = *lst;
		while (curr->next->next)
			curr = curr->next;
		elem = curr->next;
		curr->next = NULL;
	}
	return (elem);
}
