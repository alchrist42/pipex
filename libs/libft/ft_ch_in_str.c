#include "libft.h"

/*
**	@brief	checks if there is a character in the string
**	
**	@param	ch		character
**	@param	charset	pointer to set characters (string)
**	@return	int		0 if checks fail, else 1
*/
int	ft_ch_in_str(char ch, char *charset)
{
	while (*charset)
		if (*charset++ == ch)
			return (1);
	return (0);
}
