/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:45:05 by jalam             #+#    #+#             */
/*   Updated: 2023/06/27 23:57:22 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_base_valid(char *base)
{
	int	i;
	int	j;

	j = 0;
	while (base[j])
	{
		if (base[j] == '+' || base[j] == '-')
			return (0);
		j++;
	}
	if (j < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	convert_to_base(int nbr, char *base)
{
	int	base_length;

	base_length = 0;
	while (base[base_length])
		base_length++;
	if (nbr > (base_length - 1))
	{
		convert_to_base(nbr / base_length, base);
		convert_to_base(nbr % base_length, base);
	}
	else
		putchar(base[nbr]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (is_base_valid(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = nbr * -1;
		}
		convert_to_base(nbr, base);
	}
}

int	main(void)
{
	int		num;
	char	*base;

	num = 10;
	base = "01";
	ft_putnbr_base(num, base);
	return (0);
}
