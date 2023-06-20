/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:01:46 by jalam             #+#    #+#             */
/*   Updated: 2023/06/20 21:02:13 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int	x;

	x = 48;
	while (x < 58)
	{
		write(1, &x, 1);
		x++;
	}
}

int	main(void)
{
	ft_print_numbers();
	return (0);
}
