/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:20:20 by jalam             #+#    #+#             */
/*   Updated: 2023/06/20 21:26:41 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_all(int a, int b, int c, int d)
{
	char	comma;
	char	space;

	comma = 44;
	space = 32;
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &space, 1);
	write(1, &c, 1);
	write(1, &d, 1);
	write(1, &comma, 1);
	write(1, &space, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = 48;
	while (a < 58)
	{
		b = 48;
		while (b < 58)
		{
			c = 48;
			while (c < 58)
			{
				d = 48;
				while (d < 58)
				{
					if ((c * 10) + d > (a * 10) + b)
					{
						ft_print_all(a, b, c, d);
					}
					d++;
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
	ft_print_comb2();
	return (0);
}
