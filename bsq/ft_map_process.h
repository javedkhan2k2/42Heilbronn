#ifndef FT_MAP_PROCESS
# define FT_MAP_PROCESS
#include "ft_map_struct.h"

void	find_obstacles(struct s_map *s_map);
void count_obstacles(struct s_map *s_map);
void find_sqaure(struct s_map *s_map);
int find_y2(struct s_map *s_map, int x, int y);

#endif
