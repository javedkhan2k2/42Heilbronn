#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int	ft_strlen(char *str);


char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int i;
	int start;

	start = 0;
	i = ft_strlen(dest);
	while(*src && start < nb)
	{
		dest[i] = *src;
		i++;
		src++;
		start++;
	}
	dest[i] = '\0';
	return dest;
}

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

int main(void)
{
	char*		res;
	char str1[25] = "ABC";
	int length = sizeof str1;
	printf("size of str1: %d\n", length);
	char str2[] = "ABCD";
	printf("str1: %s\t str2: %s\n", str1, str2);
	res = strncat(str1, str2, 6);
	printf("res1:%s\n", res);
	char str3[5] = "ABC";
	char* res2 = ft_strncat(str3, str2, 6);
	printf("res2:%s\n", res2);
	return 0;
}
