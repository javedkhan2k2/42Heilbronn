/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <jalam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:04:26 by jalam             #+#    #+#             */
/*   Updated: 2023/07/02 17:11:21 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	get_str_len(int size, char **strs)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = 0;
	while (size > 0)
	{
		j = 0;
		while (strs[i][j])
		{
			len++;
			j++;
		}
		size--;
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	if (size == 0)
		return ((char *)malloc(1 * sizeof(char)));
	res = (char *)malloc((get_str_len(size, strs) + size) * sizeof(char));
	len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			res[len++] = strs[i][j];
			j++;
		}
		res[len++] = *sep;
		i++;
	}
	res[--len] = '\0';
	return (res);
}

int	main(void)
{
	char	**stringArray;
	char*	strings[] = {"Hello", "World", "How", "Are", "You"};
	char	*res;

	// Create the string array
	
	stringArray = strings;
	res = ft_strjoin(5, stringArray, ",");
	printf("%s\n", res);
	free(res);
	return (0);
}
