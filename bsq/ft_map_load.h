/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_load.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:09:54 by jalam             #+#    #+#             */
/*   Updated: 2023/07/04 13:20:00 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_LOAD_H
# define FT_MAP_LOAD_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_map_struct.h"

//char	*read_line(char *buffer, char *line, int *index, ssize_t bytesRead);
int read_line(struct s_map_file *map);
int		process_map(int *fd, char *name);

#endif
