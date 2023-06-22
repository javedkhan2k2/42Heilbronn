/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:05:26 by jalam             #+#    #+#             */
/*   Updated: 2023/06/22 23:13:41 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_swap_with_check(int *tab, int start, int min_index)
{
	if (start != min_index)
	{
		ft_swap(tab + start, tab + min_index);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	start;
	int	min;
	int	loop;
	int	min_index;

	start = 0;
	while (start < size - 1)
	{
		loop = start;
		min = *(tab + start);
		min_index = start;
		while (loop < size)
		{
			if (*(tab + loop) < min)
			{
				min = *(tab + loop);
				min_index = loop;
			}
			loop++;
		}
		ft_swap_with_check(tab, start, min_index);
		start++;
	}
}

int	main(void)
{
	int	size;
	int	*ptr;
	int	myarray[];

	myarray[] = {5, 3, 4, 3, 1, 3, 7, 8};
	size = 8;
	for (int i = 0; i < size; i++)
	{
		printf("%d, ", myarray[i]);
	}
	printf("\n");
	ptr = myarray;
	ft_sort_int_tab(ptr, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d, ", myarray[i]);
	}
	return (0);
}
