/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_load.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:09:54 by jalam             #+#    #+#             */
/*   Updated: 2023/07/04 00:29:12 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_LOAD_H
# define FT_MAP_LOAD_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

int		is_map_invalid(char *sym);
char	*read_line(char *buffer, char *line, int *index, ssize_t bytesRead);
int		ft_get_line_num(char *line, char *sym);
int		check_first_line(char *line);
int		process_map(int *fd, char *name);

#endif
