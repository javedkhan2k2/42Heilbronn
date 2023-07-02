#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

char		EVEN_MSG[] = "I have an even number of arguments.";
char		ODD_MSG[] = "I have an odd number of arguments.";
int			SUCCESS = 0;
int			TRUE = 1;
int			FALSE = 0;
typedef int	t_bool;

int	EVEN(int nbr)
{
	return (nbr % 2 == 0);
}

#endif
