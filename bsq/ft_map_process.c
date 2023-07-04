/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:42:27 by jalam             #+#    #+#             */
/*   Updated: 2023/07/05 01:23:28 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_process.h"
#include "stdlib.h"

void	count_obstacles(struct s_map *s_map)
{
	int	i;
	int	j;

	i = 0;
	s_map->obsnum = 0;
	while (i < s_map->y)
	{
		j = 0;
		while (j < s_map->x)
		{
			if (s_map->lines[i][j] == s_map->sym[1])
				s_map->obsnum++;
			j++;
		}
		i++;
	}
	s_map->optr = (struct s_obstacle *)malloc(s_map->obsnum
			* sizeof(struct s_obstacle));
}

void	find_obstacles(struct s_map *s_map)
{
	int	i;
	int	j;
	int	k;

	count_obstacles(s_map);
	i = 0;
	k = 0;
	while (i < s_map->y)
	{
		j = 0;
		while (j < s_map->x)
		{
			if (s_map->lines[i][j] == s_map->sym[1])
			{
				((s_map->optr) + k)->x = j;
				((s_map->optr) + k)->y = i;
				k++;
			}
			j++;
		}
		i++;
	}
	i = 0;
}

int find_y2(struct s_map *s_map, int x, int y)
{
	while(y < s_map->y)
	{
		if(s_map->lines[y][x] == s_map->sym[1])
			return (y-1);
		y++;
	}
	return (y-1);
}

void	find_sqaure(struct s_map *s_map)
{
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	int ss;
	y1 = 0;
	while(y1 < s_map->y)
	{
		x1 = 0;
		while(x1 < s_map->x - 1)
		{
			// y1,x1, y2,x1,
			y2 = find_y2(s_map, y1, x1);
			//ss = 5
			// x = 7;
			// 7+5=12 > map->x -> ss = mapx-ss = 10-5:3
			// 12-9:3
			// 0123456789
			// ..........
			if(x1+y2 > s_map->x)
				y2 = s_map->x - y2;
			x2 = x1 + y2;


			x1++;
		}

		y1++;
	}
}
