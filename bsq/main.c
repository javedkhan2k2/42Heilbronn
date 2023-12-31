/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalam <javed_alam@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:02:42 by jalam             #+#    #+#             */
/*   Updated: 2023/07/04 16:53:25 by jalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_load.h"

int	main(void)
{
	int	res;
	int	fd;

	if(process_map(&fd, "map4.txt"))
		printf("Map processed Successfully.\n");
	close(fd);
	return (0);
}
