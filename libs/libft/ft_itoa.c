#include "libft.h"

/*
**	@brief	allocates memory  for string and fills it represantation number
**	
**	@param	n		number
**	@return	char*	pointer to new string or NULL if allocation fail
*/
char	*ft_itoa(int n)
{
	char	s[12];
	int		i;
	int		minus;

	s[11] = 0;
	minus = 0;
	i = 10;
	if (!n)
		s[i--] = '0';
	if (n < 0)
	{
		s[i--] = '0' - n % 10;
		n = n / -10;
		minus = 1;
	}
	while (n)
	{
		s[i--] = '0' + n % 10;
		n = n / 10;
	}
	if (minus)
		s[i--] = '-';
	return (ft_strdup(&s[i + 1]));
}
