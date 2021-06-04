#include "libft.h"

/*
**	@brief	write integer to file descriptor
**	
**	@param	n		integer
**	@param	fd		file descriptor
*/
void	ft_putnbr_fd(long long n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n / -10)
			ft_putnbr_fd(n / -10, fd);
		ft_putchar_fd('0' - n % 10, fd);
	}
	else
	{
		if (n / -10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + n % 10, fd);
	}
}
