//#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*res;

	len = ft_strlen(src);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// int	main(void)
// {
// 	char	*str2;

// 	char str1[] = "Hello";
// 	printf("Size of Str1:%ld\n", sizeof(str1));
// 	printf("Size of Str2:%ld\n", sizeof(str2));
// 	str2 = ft_strdup(str1);
// 	printf("Str2:%s\n", str2);
// 	printf("Size of Str2:%ld\n", sizeof(str2));
// 	return (0);
// }
