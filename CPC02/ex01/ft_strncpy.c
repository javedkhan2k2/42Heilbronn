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

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int start = 0;
	int src_len;
	src_len = ft_strlen(src);
	while(src[start] && start < n)
	{
		dest[start] = src[start];
		start++;
	}
	while(start<n)
	{
		dest[start] = '\0';
		start++;
	}
	dest[start] = '\0';
	return dest;
}

int main(void)
{
	char str_src[] = "Hi";
	char str_dest[20];
	char *d = str_dest;
	char *s = str_src;
	char *ptr;
	ptr = ft_strncpy(d, s, 8);
	put_ch(ptr);
	printf("\n");
	return 0;
}
