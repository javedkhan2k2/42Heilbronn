#include <stdio.h>
#include<unistd.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
		count++;
	return count;
}

void put_ch(char* str)
{
	while(*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

char	*ft_strcpy(char *dest, char *src)
{
	int start;

	start = 0;
	while(src[start])
	{
		dest[start] = src[start];
		start++;
	}
	dest[start] = '\0';
	return dest;
}

int main(void)
{
	char str_src[] = "Hello";
	char str_dest[4] = "";
	char *ptr;

	printf("Dest before copy: %s\n", str_dest);
	ptr = ft_strcpy(str_dest, str_src);
	printf("Dest after Copy: \n");
	put_ch(ptr);
	printf("\n");
	return (0);
}
