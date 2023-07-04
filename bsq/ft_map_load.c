/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:03:26 by jalam             #+#    #+#             */
/*   Updated: 2023/07/04 15:57:48 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_load.h"
#include "ft_str.h"
#include "ft_validate_map.h"

int read_line(struct s_map_file *map)
{
	int	line_index;

	line_index = 0;
	while (map->idx < map->bytes_read && map->buffer[map->idx] != '\n')
	{
		map->line[line_index] = map->buffer[map->idx];
		line_index++;
		map->idx++;
	}
	if(map->idx >= map->bytes_read && map->buffer[map->idx] != '\n')
		return (0);
	map->idx++;
	map->line[line_index] = '\0';
	return (1);
}

int	process_map(int *fd, char *name)
{
	struct s_map_file s_map;

	*fd = open(name, O_RDONLY);
	if (*fd == -1)
	{
		perror("Error opening the file");
		return (0);
	}
	s_map.bytes_read = read(*fd, s_map.buffer, sizeof(s_map.buffer));
	if (s_map.bytes_read == -1)
	{
		perror("Error reading the file");
		close(*fd);
		return (0);
	}
	s_map.num_of_lines = 0;
	s_map.idx = 0;
	read_line(&s_map);
	printf("%s\n", s_map.line);

	if(!is_map_valid(&s_map))
	{
		printf("map error\n");
		return (0);
	}

	return (1);
}
