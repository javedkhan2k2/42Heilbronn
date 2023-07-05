/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:57:55 by jalam             #+#    #+#             */
/*   Updated: 2023/07/06 00:35:49 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int	get_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int is_in_sep(char ch, char *charset)
{
	int len;
	int i;

	len = get_strlen(charset);
	i = 0;
	while (i < len)
	{
		if(ch == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int count_strings(char *str, char *charset)
{
	int count;
	int i;
	int k;

	count = 0;
	i = 0;
	k = -1;
	while(str[i])
	{
		if(is_in_sep(str[i], charset))
		{
			if( k == -1)
				count++;
			else if(i - k > 1 && (i+1) < get_strlen(str))
				count++;
			k = i;
		}
		i++;
	}
	return (count);
}

void	ft_strdup_ultimate(char *src, int start, int end, char **ptr, int *count)
{
	int		len;
	int		i;
	char	*res;

	len = end-start+1;
	res = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	while (start <= end)
	{
		//printf("%c\n", src[i]);
		res[i] = src[start];
		i++;
		start++;
	}
	res[i] = '\0';
	ptr[*count] = res;
	*count = *count + 1;
}

char	**ft_split(char *str, char *charset)
{
	int count;
	char **ptr;
	int start;
	int i;

	count = count_strings(str, charset);
	//printf("Words: %d\n", count);
	ptr = (char **)malloc(count*sizeof(char*));
	if(!ptr)
		return (NULL);
	i = 0;
	count = 0;
	while(str[i])
	{
		if(is_in_sep(str[i], charset))
		{
			i++;
			if(!str[i])
				break;
			start = i;
			while(str[i] && !is_in_sep(str[i], charset))
				i++;
			i--;
			ft_strdup_ultimate(str, start, i, ptr, &count);
		}
		i++;
	}
	for(int m=0;m<4;m++)
		printf("%s\n", ptr[m]);
	return (0);
}


int	main(void)
{
	char	**ptr;

	char *str = "eHello, i am doing fined";
	char *set = "eo";
	printf("Str: %s\n", str);
	printf("Set: %s\n", set);
	ptr = ft_split(str, set);
	return (0);
}
