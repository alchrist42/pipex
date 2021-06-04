#include "libft.h"

/*
 * @brief free all alocated pointer in split
 * 
 * @param arr pointer to pointers (array of strings)
 */
void	ft_split_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
