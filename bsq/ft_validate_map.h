#ifndef FT_VALIDATE_MAP_H
# define FT_VALIDATE_MAP_H

#include "ft_map_struct.h"

int	is_map_valid(struct s_map_file *map);
int	validate_sym_y(struct s_map_file *map);
int	get_x(struct s_map_file *s_map);

#endif
