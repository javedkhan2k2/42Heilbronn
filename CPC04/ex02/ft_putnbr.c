#include <unistd.h>

void ft_putnbr(int nb)
{
	char minus;
	int mod;
	int div;

	minus = '-';
	if (nb < 0)
	{
		write(1, &minus, 1);
		nb = nb * -1;
	}

	mod = nb % 10;
	div = nb / 10;
	if(div > 0)
		ft_putnbr(div);
	mod += 48;
	write(1, &mod, 1);
}

int main(void)
{
	ft_putnbr(421);
	ft_putnbr(-421);
	return 0;
}
