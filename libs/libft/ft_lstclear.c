#include "libft.h"

/*
**	@brief	deletes and frees the given element and every successor of that element
**	
**	@param	lst		the addres of a pointer to the list
*/
void	ft_lstclear(t_list **lst)
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = next;
	}
}
