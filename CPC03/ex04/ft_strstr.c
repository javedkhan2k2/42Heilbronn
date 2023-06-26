/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:16:30 by jalam             #+#    #+#             */
/*   Updated: 2023/06/26 21:44:12 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
		The  strstr() function finds the first occurrence of the substring nee‐
		dle in the string haystack.  The terminating null bytes ('\0') are  not
		compared.

		The  strcasestr()  function  is  like strstr(), but ignores the case of
		both arguments.

RETURN VALUE
		These functions return a pointer to the beginning of the  located  sub‐
		string, or NULL if the substring is not found.


*/
#include <stdio.h>

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

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
	{
		count++;
	}
	return (count);
}

char	*ft_strstr(char *str, char *to_find)
{
	int to_find_length;
	char *index = NULL;
	int j;
	to_find_length = ft_strlen(to_find);
	if(to_find_length == 0)
		return NULL;
	while (*str)
	{
		if(*str == to_find[0] && ft_strncmp(str, to_find, to_find_length) == 0)
		{
			return str;
		}
		str++;
	}

	return (NULL);
}

int	main(void)
{
	char s1[] = "Hello Andy, how are you doing. Lisa was asking about you";
	char s2[] = "";
	char* res = ft_strstr(s1,s2);
	printf("\nRes:%s\n", res);
	return (0);
}
