/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:54:36 by jalam             #+#    #+#             */
/*   Updated: 2023/06/20 20:57:42 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int	x;

	x = 122;
	while (x >= 97)
	{
		write(1, &x, 1);
		x--;
	}
}

int	main(void)
{
	ft_print_reverse_alphabet();
	return (0);
}
