#include <stdio.h>
#include<unistd.h>

int	ft_str_is_lowercase(char *str)
{
	while(*str)
	{
		if( !(*str >= 97 && *str <=122))
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
	char str[] = "hello";
	char* ptr = str;
	int x = ft_str_is_lowercase(ptr);
	printf("%d\n", x);
	return 0;
}
