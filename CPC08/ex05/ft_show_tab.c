#include "ft_stock_str.h"
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

void	ft_putstr(char *str)
{
	int	length;

	length = ft_strlen(str);
	write(1, str, length);
}

void	ft_putnbr(int nb)
{
	long	lb;
	char	ch;

	lb = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		lb = lb * -1;
	}
	if (lb > 9)
		ft_putnbr(lb / 10);
	ch = (lb % 10) + 48;
	write(1, &ch, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while ((par + i)->str)
	{
		ft_putstr((par + i)->str);
		write(1, "\n", 1);
		ft_putnbr((par + i)->size);
		write(1, "\n", 1);
		ft_putstr((par + i)->copy);
		write(1, "\n", 1);
		i++;
	}
}
