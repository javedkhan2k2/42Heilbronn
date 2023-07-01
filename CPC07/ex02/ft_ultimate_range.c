#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int len;
	int start;

	if(min >= max)
	{
		range = NULL;
		return (0);
	}

	len = max - min;
	range = (int**) malloc(len*sizeof(int));
	if(!range)
		return (-1);
	start = 0;
	while(start < len)
	{
		*range[start] = min;
		start++;
		min++;
	}
	return (len);

}

int main(void)
{
	int x[3][5]={{1,2,10,4,5},{6,7,1,9,10},{11,12,13,14,15}};
	// *x = address of first byte
	//**x:1, **(x+1):6, **(x+2):11


	for(int i=0;i<3;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf("%d, ",x[i][j]);
		}
		printf("\n");
		for(int j=0;j<5;j++)
		{
			printf("%d, ", **x(i+j));
		}
		printf("\n");
	}
	// int **ptr = NULL;
	// int size = ft_ultimate_range(ptr, 1, 10);
	// for(int i=0;i<size;i++)
	// 	printf("%d, ", *ptr[i]);
	// printf("\n");
	return (0);
}
