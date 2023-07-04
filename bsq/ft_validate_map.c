/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:15:21 by jalam             #+#    #+#             */
/*   Updated: 2023/07/04 13:51:11 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_struct.h"
#include "ft_str.h"
#include "ft_validate_map.h"
#include "ft_map_load.h"
#include <stdio.h>

int	is_map_valid(struct s_map_file *s_map)
{
	int	i;

	if (!validate_sym_y(s_map))
		return (0);
	if(!get_x(s_map))
		return (0);
	return (1);
}

int	validate_sym_y(struct s_map_file *s_map)
{
	int	i;

	s_map->y = 0;
	i = 0;
	while (s_map->line[i] >= 48 && s_map->line[i] <= 57)
		s_map->y = (s_map->y * 10) + s_map->line[i++] - 48;
	if (s_map->y != 0)
	{
		if ((ft_strlen(s_map->line) - i) != 3)
			return (0);
		ft_strncpy(s_map->sym, (s_map->line + i), 3);
	}
	if (s_map->y == 0)
	{
		printf("map Error in check_first_line();\n");
		return (-1);
	}
	i = 0;
	if (s_map->sym[0] == s_map->sym[1] || s_map->sym[0] == s_map->sym[2]
		|| s_map->sym[1] == s_map->sym[2])
		return (0);
	i = 0;
	while ((s_map->sym[i] >= 0 && s_map->sym[i] <= 31) || s_map->sym[i] == 127)
		return (0);
	return (1);
}

int	get_x(struct s_map_file *s_map)
{
	int temp_idx;
	int s;

	temp_idx = s_map->idx;
	s = 0;
	while(read_line(s_map))
	{
		s++;
	}
	printf("num of lines are: %d\n", s);
	return (0);
}
