#include <stdlib.h>

//#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	start;
	int	*ptr;

	if (min >= max)
		return (NULL);
	len = max - min;
	ptr = (int *)malloc(len * sizeof(int));
	if (!ptr)
		return (NULL);
	start = 0;
	while (start < len)
	{
		ptr[start] = min;
		start++;
		min++;
	}
	return (ptr);
}

// int main(void)
// {
// 	int *new = ft_range(11,10);
// 	printf("\n");
// 		return (0);
// 	for(int i=0;i<9;i++)
// 		printf("%d, ", new[i]);
// 	printf("\n");
// 	return (0);
// }
