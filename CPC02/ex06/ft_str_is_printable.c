#include <stdio.h>
#include<unistd.h>

int	ft_str_is_printable(char *str)
{
	while(*str)
	{
		//printf("%d, ", *str);
		// printf("%d:%d\n", *str, *str >= 65);
		// printf("%d:%d\n", *str, *str <=90);
		if( !(*str >= 32 && *str <126))
		{
			return 0;
		}
		//write(1, &*str,1);
		str++;
	}
	return 1;
}

int main(void)
{
	char str[] = "Hello";
	char* ptr = str;
	int x = ft_str_is_printable(ptr);
	printf("%d\n", x);
	return 0;
}
