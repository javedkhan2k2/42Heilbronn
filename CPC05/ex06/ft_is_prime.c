#include<stdio.h>

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

int main(void)
{
	for(int i=0;i<100;i++)
		printf("%d is:%d\t",i, ft_is_prime(i));
	return (0);
}
