/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:01:53 by jalam             #+#    #+#             */
/*   Updated: 2023/06/29 22:04:18 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	swap_str(char **value, int i, int j)
{
	char	*temp;

	temp = value[i];
	value[i] = value[j];
	value[j] = temp;
}

void	sort_args(int count, char **value)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i < count)
	{
		j = i + 1;
		temp = i;
		while (j < count)
		{
			if (ft_strcmp(value[temp], value[j]) > 0)
				temp = j;
			j++;
		}
		swap_str(value, i, temp);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	start;

	sort_args(argc, argv);
	start = 1;
	while (start < argc)
	{
		ft_putstr(argv[start]);
		start++;
	}
	return (0);
}
