/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:12:43 by jalam             #+#    #+#             */
/*   Updated: 2023/06/20 21:13:20 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	postive;
	char	negative;

	postive = 'P';
	negative = 'N';
	if (n >= 0)
	{
		write(1, &postive, 1);
	}
	else if (n < 0)
	{
		write(1, &negative, 1);
	}
}

int	main(void)
{
	ft_is_negative(-3);
	ft_is_negative(3);
	return (0);
}
