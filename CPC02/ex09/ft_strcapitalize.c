/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:42:03 by jalam             #+#    #+#             */
/*   Updated: 2023/06/23 20:42:49 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	to_upper(char *ch)
{
	if (*ch >= 97 && *ch <= 122)
	{
		*ch = *ch - 32;
	}
}

void	to_lower(char *ch)
{
	if (*ch >= 65 && *ch <= 90)
	{
		*ch = *ch + 32;
	}
}

int	is_alpha(char ch)
{
	if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48
			&& ch <= 57))
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	cursor;

	cursor = 0;
	while (str[cursor] != '\0')
	{
		if (is_alpha(str[cursor]))
		{
			to_upper(&str[cursor]);
			cursor++;
			while (is_alpha(str[cursor]) && str[cursor] != '\0')
			{
				to_lower(&str[cursor]);
				cursor++;
			}
		}
		cursor++;
	}
	return (str);
}

int	main(void)
{
	// char	str[];
	// char	*ptr;
	// char	*ptr2;
	// str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	// printf("%s\n", str);
	// ptr = str;
	// ptr2 = ft_strcapitalize(ptr);
	// printf("%s\n", ptr2);
	return (0);
}
