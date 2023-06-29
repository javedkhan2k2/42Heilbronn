#include <unistd.h>
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

int main(int argc, char *argv[])
{
	int start;

	start = argc - 1;
	while(start > 0)
		ft_putstr(argv[start--]);
	return (0);
}
