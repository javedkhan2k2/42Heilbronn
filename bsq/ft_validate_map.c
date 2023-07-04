/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:15:21 by jalam             #+#    #+#             */
/*   Updated: 2023/07/04 16:47:27 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_load.h"
#include "ft_map_struct.h"
#include "ft_str.h"
#include "ft_validate_map.h"
#include <stdio.h>

int	is_map_valid(struct s_map_file *s_map)
{
	int	i;

	if (!get_y(s_map) || !get_x(s_map, s_map->idx) || !chk_lines(s_map,
			s_map->idx))
		return (0);
	return (1);
}

/*
 * Find the number of lines and assign it to y
 * Check if empty, Obstacles and Print character are given and assign it to sym
 * Check if any sym is repeat
 * Check if the sym are printable
 */
int	get_y(struct s_map_file *s_map)
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
		return (0);
	i = 0;
	if (s_map->sym[0] == s_map->sym[1] || s_map->sym[0] == s_map->sym[2]
		|| s_map->sym[1] == s_map->sym[2])
		return (0);
	i = 0;
	while ((s_map->sym[i] >= 0 && s_map->sym[i] <= 31) || s_map->sym[i] == 127)
		return (0);
	return (1);
}

/*
 * Check every line length is same
 * Also check the number of lines with the actual provided in first line
 * After success assign the length to x
 */
int	get_x(struct s_map_file *s_map, int tidx)
{
	int	s;
	int	len;

	s = 0;
	len = -1;
	while (read_line(s_map))
	{
		if (len == -1)
			len = ft_strlen(s_map->line);
		if (len != ft_strlen(s_map->line))
			return (0);
		s++;
	}
	if (s_map->y != s)
		return (0);
	s_map->x = s;
	s_map->idx = tidx;
	return (1);
}

/*
 * The characters on the map can only be those introduced in the first line.
 */
int	chk_lines(struct s_map_file *s_map, int tidx)
{
	int	i;
	int	j;
	int	res;

	while (read_line(s_map))
	{
		i = 0;
		while (s_map->line[i])
		{
			j = 0;
			res = 0;
			while (j < 3)
				if (s_map->line[i] == s_map->sym[j++])
					res = 1;
			if (!res)
				return (0);
			i++;
		}
	}
	return (1);
}
