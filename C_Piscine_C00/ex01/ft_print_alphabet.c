/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:59:41 by jalam             #+#    #+#             */
/*   Updated: 2023/06/20 21:01:15 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int	x;

	x = 97;
	while (x < 123)
	{
		write(1, &x, 1);
		x++;
	}
}

int	main(void)
{
	ft_print_alphabet();
	return (0);
}
