#include <stdio.h>
#include<unistd.h>

int	ft_str_is_numeric(char *str)
{
	while(*str)
	{
		//printf("%d, ", *str);
		// printf("%d:%d\n", *str, *str >= 65);
		// printf("%d:%d\n", *str, *str <=90);
		if( !(*str >= 48 && *str <=57))
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
	char str[] = " 12345";
	char* ptr = str;
	int x = ft_str_is_numeric(ptr);
	printf("%d\n", x);
	return 0;
}
