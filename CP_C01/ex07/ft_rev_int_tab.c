#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int start = 0;
	int end = size;
	while(start < end)
	{
		printf("start is:%d, end is:%d\n", start, end);
		ft_swap(tab+start, tab+end-1);
		start++;
		end--;

	}
}

int main(void)
{
	int myarray[] = {1,2,3,4,5,6,7,8};
	int size = 8;
	int* ptr = myarray;
	ft_rev_int_tab(ptr, size);
	for(int i=0;i<size;i++)
	printf("%d, ", myarray[i]);
	return (0);
}

