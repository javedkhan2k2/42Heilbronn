
int ft_sqrt(int nb)
{
	if (nb < 0)
		return 0;
	if(nb == 0 || nb == 1)
		return (1);

	int i;
	int end;

	end = nb/2;
	i=1;
	while(i <= end)
	{
		if(i*i == nb)
			return i;
		i++;
	}
	return 0;
}

#include <stdio.h>
int main(void)
{
	for(int i=0;i<100;i++)
		printf("sqrt(%d):%d\t",i, ft_sqrt(i));
	return (0);
}
