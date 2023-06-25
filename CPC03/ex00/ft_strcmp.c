/*
DESCRIPTION
		The strcmp() function compares the two strings s1 and s2.  The locale is not taken into account (for a locale-aware comparison,
			see
		strcoll(3)).  The comparison is done using unsigned characters.

		strcmp() returns an integer indicating the result of the comparison,
			as follows:

		• 0, if the s1 and s2 are equal;

		• a negative value if s1 is less than s2;

		• a positive value if s1 is greater than s2.
EXAMPLES
		The  program  below can be used to demonstrate the operation of strcmp() (when given two arguments) and strncmp() (when given three
		arguments).  First, some examples using strcmp():

			$ ./string_comp ABC ABC
			<str1> and <str2> are equal
			$ ./string_comp ABC AB      # 'C' is ASCII 67; 'C' - ' ' = 67
			<str1> is greater than <str2> (67)
			$ ./string_comp ABA ABZ     # 'A' is ASCII 65; 'Z' is ASCII 90
			<str1> is less than <str2> (-25)
			$ ./string_comp ABJ ABC
			<str1> is greater than <str2> (7)

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int	ft_strcmp(char *s1, char *s2)
{
	while(*s1 || *s2)
	{
		if(*s1 > *s2)
			return 1;
		else if(*s1 < *s2)
			return -1;
		s1++;
		s2++;
	}
	return 0;
}

int	main(void)
{
	int		res;

	char str1[] = "~";
	char str2[] = "B";
	printf("str1: %s\t str2: %s\n", str1, str2);
	res = ft_strcmp(str1, str2);
	if (res == 0)
	{
		printf("<str1> and <str2> are equal");
		printf("\n");
	}
	else if (res < 0)
	{
		printf("<str1> is less than <str2> (%d)\n", res);
	}
	else
	{
		printf("<str1> is greater than <str2> (%d)\n", res);
	}
	return (0);
}
