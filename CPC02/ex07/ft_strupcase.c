#include <stdio.h>
#include<unistd.h>

char	*ft_strupcase(char *str)
{
	int i = 0;
	while(str[i])
	{
		//printf("%d, ", *str);
		// printf("%d:%d\n", *str, *str >= 65);
		// printf("%d:%d\n", *str, *str <=90);
		if( str[i] >= 97 && str[i] <122)
		{
			str[i] = str[i] - 32;
		}
		//write(1, &*str,1);
		i++;
	}
	str[i] = '\0';
	return str;
}

int main(void)
{
	char str[] = "Hel1lo";
	char* ptr = str;
	char* ptr2 = ft_strupcase(ptr);
	printf("%s\n", ptr2);
	return 0;
}
