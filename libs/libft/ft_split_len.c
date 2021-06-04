#include "libft.h"

/*
 * @brief	gets len the nullterminated array of string
 * 
 * @param arr	pointer to array
 * @return int	count strings in array
 */
int	ft_split_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
