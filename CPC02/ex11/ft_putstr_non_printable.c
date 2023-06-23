#include <stdio.h>
#include<unistd.h>

int	is_printable(char ch)
{
	if(ch >= 32 && ch <= 126)
	{
		return 1;
	}
	return 0;
}

static void	print_hex(int np)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (np > 16)
	{
		print_hex(np / 10);
		print_hex(np % 10);
	}
	else
		write(1, &hex[np], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!is_printable(str[i]))
		{
			write(1, "\\", 1);
			if (str[i] < 16)
				write(1, "0", 1);
			print_hex(str[i]);
		}
		else
			write(1, &str[i], 1);
		i += 1;
	}
}

int main(void)
{
	char str[] = "Coucou\ntu vas bien ?";
	//printf("%s\n", str);
	char* ptr = str;
	ft_putstr_non_printable(ptr);
	return 0;
}
