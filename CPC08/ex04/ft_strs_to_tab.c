#include "ft_stock_str.h"
#include <stdlib.h>

int ft_strlen(char *str)
{
	int c;

	c = 0;
	while(str[c])
		c++;
	return (c);
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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*ptr;
	int i;

	ptr = (struct s_stock_str *)(malloc(ac * sizeof(struct s_stock_str)));
	if(!ptr)
		return (NULL);
	i = 0;
	while(i < ac)
	{
		(ptr+i)->size = ft_strlen(av[i]);
		(ptr+i)->str = av[i];
		(ptr+i)->copy = ft_strdup(av[i]);
		i++;
	}
	(ptr+i-1)->str = 0;
	return (ptr);
}
