#ifndef FT_MAP_STRUCT_H
# define FT_MAP_STRUCT_H

# include <unistd.h>

struct s_map_file
{
	int		num_of_lines;
	int		idx;
	int		x;
	int		y;
	char	*first_line;
	ssize_t	bytes_read;
	char	buffer[1024];
	char	line[1024];
	char	sym[4];
};

#endif
