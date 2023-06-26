#include <unistd.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
	{
		count++;
	}
	return (count);
}

void	ft_putstr(char *str)
{
	int length;

	length = ft_strlen(str);
	write(1, str, length);
}

int main(void)
{
	char str[] = "Hello World";
	ft_putstr(str);
	return 0;
}
