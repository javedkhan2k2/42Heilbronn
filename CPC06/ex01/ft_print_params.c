#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int ft_putstr(char *str)
{
	int len;

	len = ft_strlen(str);
	write(1, str, len);
	write(1, "\n", 1);
}

int main(int arg, char *argv[])
{
	int start;

	start = 1;
	while(start < arg)
		ft_putstr(argv[start++]);
	return (0);
}
