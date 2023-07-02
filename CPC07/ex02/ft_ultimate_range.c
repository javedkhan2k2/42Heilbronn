#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int len;
	int start;

	if(min >= max)
	{
		*range = NULL;
		return (0);
	}

	len = max - min;
	//printf("Len:%d\n", len);
	*range = (int*) malloc(len*sizeof(int));

	if(!*range)
		return (-1);
	start = 0;
	//printf("Len:%p\n", *range);
	while(start < len)
	{
		//printf("%d,", start);
		//(*range)[start] = min;
		*(*range+start) = min;
		start++;
		min++;
		//**range = **range + 1;
	}
	return (len);
}
//#include <stdio.h>
// int main(void)
// {
// 	int *ptr;
// 	int res = ft_ultimate_range(&ptr, 0, 0);
// 	if(res == -1)
// 		return (0);
// 	for(int i=0;i<res;i++)
// 		printf("%d, ", ptr[i]);
// 	printf("\n");
// 	return (0);
// }
