/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:43:48 by jalam             #+#    #+#             */
/*   Updated: 2023/06/20 21:44:18 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	mod;
	int	div;

	mod = nb % 10;
	mod = mod + 48;
	div = nb / 10;
	if (div > 0)
	{
		ft_putnbr(div);
	}
	write(1, &mod, 1);
}

int	main(void)
{
	ft_putnbr(123456);
	return (0);
}
