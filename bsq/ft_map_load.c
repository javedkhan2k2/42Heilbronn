/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:03:26 by jalam             #+#    #+#             */
/*   Updated: 2023/07/04 00:29:51 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_load.h"
#include "ft_str.h"

int	is_map_invalid(char *sym)
{
	int	i;

	if (sym[0] == sym[1] || sym[0] == sym[2] || sym[1] == sym[2])
		return (0);
	i = 0;
	while ((sym[i] >= 0 && sym[i] <= 31) || sym[i] == 127)
		return (0);
	return (1);
}

char	*read_line(char *buffer, char *line, int *index, ssize_t bytes_read)
{
	int	line_index;

	line_index = 0;
	while (*index < bytes_read && buffer[*index] != '\n')
	{
		line[line_index] = buffer[*index];
		line_index++;
		*index = *index + 1;
	}
	*index = *index + 1;
	line[line_index] = '\0';
	return (line);
}

int	ft_get_line_num(char *line, char *sym)
{
	int	res;
	int	i;
	int	j;

	res = 0;
	i = 0;
	while (line[i] >= 48 && line[i] <= 57)
	{
		res = (res * 10) + line[i] - 48;
		i++;
	}
	j = 0;
	if (res != 0)
	{
		if ((ft_strlen(line) - i) != 3)
			return (0);
		else
		{
			sym = ft_strncpy(sym, (line + i), 3);
			printf("Symbols: %s\n", sym);
			if (!is_map_invalid(sym))
			{
				return (0);
			}
		}
	}
	return (res);
}

int	check_first_line(char *line)
{
	char	symbols[4];
	int		line_num;

	printf("%s\n", line);
	line_num = ft_get_line_num(line, symbols);
	if (line_num == 0)
	{
		printf("map Error\n");
		return (-1);
	}
	printf("Line Num is:%d\n", line_num);
	return (1);
}

int	process_map(int *fd, char *name)
{
	int		num_of_lines;
	int		i;
	char	*first_line;
	ssize_t	bytes_read;
	char	buffer[1024];
	char	line[1024];

	*fd = open(name, O_RDONLY);
	if (*fd == -1)
	{
		perror("Error opening the file");
		return (1);
	}
	bytes_read = read(*fd, buffer, sizeof(buffer));
	if (bytes_read == -1)
	{
		perror("Error reading the file");
		close(*fd);
		return (1);
	}
	num_of_lines = 0;
	i = 0;
	first_line = read_line(buffer, line, &i, bytes_read);
	check_first_line(first_line);
	return (1);
}
