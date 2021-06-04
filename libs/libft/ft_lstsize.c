#include "libft.h"

/*
**	@brief	counts the number of elements in a list
**	
**	@param	lst		pointer to the list begin
**	@return	int	lenght of the list
*/
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
