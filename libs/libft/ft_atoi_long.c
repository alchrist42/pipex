#include "libft.h"

/*
**	@brief	tests that character is space symbol (\t \n \v \r \f and space)
**	
**	@param	ch		character
**	@return	int	zero if test false, else 1
*/
static int	is_space(char ch)
{
	if ((ch >= 9 && ch <= 13) || ch == ' ')
		return (1);
	return (0);
}

/*
**	@brief	converts initial portion of string digits  to int representation
**	
**	@param	str		pointer to string with digits
**	@param	x		pointer to puts new integer
**	@return	int		0 if sting representation integer is correct
*/
long long	ft_atoi_long(const char *str, long long *x)
{
	long long	new_x;
	int			minus;

	new_x = 0;
	minus = -1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			minus = 1;
	while (*str && ft_isdigit(*str))
	{
		new_x = new_x * 10 - (*str++ - '0');
		if (new_x < INT_MIN + (minus == 1))
			return (-1);
	}
	*x = new_x * minus;
	return (*str);
}
