/*
DESCRIPTION
       The strcmp() function compares the two strings s1 and s2.  The locale is not taken into account (for a locale-aware comparison, see
       strcoll(3)).  The comparison is done using unsigned characters.

       strcmp() returns an integer indicating the result of the comparison, as follows:

       • 0, if the s1 and s2 are equal;

       • a negative value if s1 is less than s2;

       • a positive value if s1 is greater than s2.

       The strncmp() function is similar, except it compares only the first (at most) n bytes of s1 and s2.

		$ ./string_comp ABC AB 3
		<str1> is greater than <str2> (67)
		$ ./string_comp ABC AB 2
		<str1> and <str2> are equal in the first 2 bytes
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{

	int i;
	i=0;
	while (i<n && (s1[i] || s2[i]))
	{
		if(s1[i] > s2[i])
			return 1;
		else if(s1[i] < s2[i])
			return -1;
		i++;
	}

	return 0;
}

int	main(void)
{
	int		res;
	int n;
	n = 5;
	char str1[] = "ABC";
	char str2[] = "ABCD";
	printf("str1: %s\t str2: %s\n", str1, str2);
	res = strncmp(str1, str2, n);
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

	res = ft_strncmp(str1, str2, n);
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
