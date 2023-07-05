# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalam <jalam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 14:58:44 by jalam             #+#    #+#              #
#    Updated: 2023/07/05 14:58:50 by jalam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS="-Wall -Wextra -Werror"

SOURCE_FILES=("ft_putchar.c" "ft_swap.c" "ft_putstr.c" "ft_strlen.c" "ft_strcmp.c")

LIBRARY_NAME="ft"

$CC $CFLAGS -c "${SOURCE_FILES[@]}"
ar rcs lib$LIBRARY_NAME.a *.o
rm -f *.o
