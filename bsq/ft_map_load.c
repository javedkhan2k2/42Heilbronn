/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:03:26 by jalam             #+#    #+#             */
/*   Updated: 2023/07/04 21:58:09 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_load.h"
#include "ft_map_process.h"
#include "ft_str.h"
#include "ft_validate_map.h"
#include "stdlib.h"

int	read_line(struct s_map *s_map)
{
	int	line_index;

	line_index = 0;
	while (s_map->idx < s_map->bytes_read && s_map->buffer[s_map->idx] != '\n')
	{
		s_map->line[line_index] = s_map->buffer[s_map->idx];
		line_index++;
		s_map->idx++;
	}
	if (s_map->idx >= s_map->bytes_read && s_map->buffer[s_map->idx] != '\n')
		return (0);
	s_map->idx++;
	s_map->line[line_index] = '\0';
	return (1);
}

int	open_read_map(int *fd, char *name, struct s_map *s_map)
{
	*fd = open(name, O_RDONLY);
	if (*fd == -1)
	{
		perror("Error opening the file");
		return (0);
	}
	s_map->bytes_read = read(*fd, s_map->buffer, sizeof(s_map->buffer));
	if (s_map->bytes_read == -1)
	{
		perror("Error reading the file");
		return (0);
	}
	s_map->num_of_lines = 0;
	s_map->idx = 0;
	if (!read_line(s_map))
		return (0);
	return (1);
}

void	assign_map(struct s_map *s_map, int tidx)
{
	int	i;

	s_map->lines = (char **)malloc(s_map->y * sizeof(char *));
	i = 0;
	while (read_line(s_map))
	{
		s_map->lines[i] = ft_strdup(s_map->line);
		i++;
	}
	s_map->idx = tidx;
}

int	process_map(int *fd, char *name)
{
	struct s_map	s_map;

	if (!open_read_map(fd, name, &s_map))
		return (0);
	if (!is_map_valid(&s_map))
	{
		printf("map error\n");
		return (0);
	}
	assign_map(&s_map, s_map.idx);
	find_obstacles(&s_map);
	find_sqaure(&s_map);
	return (1);
}
