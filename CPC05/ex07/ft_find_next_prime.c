#include <stdio.h>

int ft_is_prime(int nb)
{
	if (nb == 0 || nb == 1)
		return (0);
	int i;

	i = 2;
	while(i < nb)
	{
		if(nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int ft_find_next_prime(int nb)
{
	int i;
	int end;

	i = nb;
	if(nb == 0 || nb == 1)
		i = 2;
	end = 2147483647;
	while(i<end)
	{
		if(ft_is_prime(i))
			return (i);
		i++;
	}
	return (0);
}

int main(void)
{
	for(int i=0;i<100;i++)
		printf("%d next prime is:%d\n",i, ft_find_next_prime(i));
	return (0);
}
