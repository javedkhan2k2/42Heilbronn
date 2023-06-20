/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:13:49 by jalam             #+#    #+#             */
/*   Updated: 2023/06/20 21:19:44 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb_scr(int a, int b, int c)
{
	char	comma;
	char	space;

	comma = 44;
	space = 32;
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	write(1, &comma, 1);
	write(1, &space, 1);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 48;
	while (a < 57)
	{
		b = a + 1;
		while (b < 58)
		{
			c = b + 1;
			while (c < 58)
			{
				if (a != b && b != c && a != c)
				{
					ft_print_comb_scr(a, b, c);
				}
				c++;
			}
			b++;
		}
		a++;
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
