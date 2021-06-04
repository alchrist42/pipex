#include "libft.h"

/*
**	@brief	adds the element ’new’ at the beginning of the list
**	
**	@param	lst		pointer to list
**	@param	new		pointer to new element
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
