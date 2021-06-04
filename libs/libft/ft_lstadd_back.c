#include "libft.h"

/*
**	@brief	adds new element to the end of the list
**	
**	@param	lst		pointer to list
**	@param	new		pointer to new element
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
