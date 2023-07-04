#ifndef FT_VALIDATE_MAP_H
# define FT_VALIDATE_MAP_H

#include "ft_map_struct.h"

int	is_map_valid(struct s_map *map);
int	get_y(struct s_map *s_map);
int	get_x(struct s_map *s_map , int tidx);
int chk_lines(struct s_map *s_map, int tidx);

#endif
