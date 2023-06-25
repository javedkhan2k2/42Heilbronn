/*
DESCRIPTION
		The  strcat()  function appends the src string to the dest string,
			overwriting the terminating null byte ('\0') at the end of dest,
		and then adds a terminating null byte.  The strings may not overlap,
			and the dest string must have enough space for the result.  If
		dest is not large enough,
			program behavior is unpredictable; buffer overruns are a favorite avenue for attacking secure programs.

		The strncat() function is similar, except that

		*  it will use at most n bytes from src; and

		*  src does not need to be null-terminated if it contains n or more bytes.

		As with strcat(),
			the resulting string in dest is always null-terminated.

		If  src  contains  n or more bytes,
			strncat() writes n+1 bytes to dest (n from src plus the terminating null byte).  Therefore,
			the
		size of dest must be at least strlen(dest)+n+1.

*/
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

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

char	*ft_strcat(char *dest, char *src)
{
	int i;
	i = ft_strlen(dest);
	while(*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return dest;
}

int main(void)
{
	char*		res;
	char str1[5] = "ABC";
	int length = sizeof str1;
	printf("size of str1: %d\n", length);
	char str2[] = "ABCD";
	printf("str1: %s\t str2: %s\n", str1, str2);
	res = strcat(str1, str2);
	printf("res:%s\n", res);
	char str3[5] = "ABC";
	char* res2 = ft_strcat(str3, str2);
	printf("res:%s\n", res2);
	return 0;
}
