/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:00:04 by bbehm             #+#    #+#             */
/*   Updated: 2019/11/28 10:09:49 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	struct_maker(t_struct **pieces, char *tetri)
{
	int i;
	int y;
	int c[4][2];
	int a;
	t_struct *piece;

	a = 0;
	y = 0;
	i = 0;
	if (!(piece = (t_struct *)malloc(sizeof(t_struct))))
		return ;
	while (tetri[i] != '\0')
	{
		while (tetri[i] < 65 || tetri[i] > 90)
		{
			if (tetri[i] == '\n')
				y++;
			i++;
		}
		if (tetri[i] > 64 && tetri[i] < 91)
		{
			c[a][0] = y;
			c[a++][1] = i;
			i++;
		}
	}
	piece->one[0] = c[0][0];
	piece->one[1] = c[0][1];
//	piece->two = ;
//	piece->three = ;
//	piece->four = ;
	piece->next = pieces;
}

#include <stdio.h>

t_struct	**list_maker(char **tetrimino, int size)
{
	t_struct *pieces;
	int i;

	i = 0;
	if (!(pieces = (t_struct *)malloc(sizeof(t_struct) * size)))
			return (NULL);
	while (i < size)
	{
		struct_maker(&pieces, tetrimino[i]);
		i++;
	}
	printf("%d, ", pieces->one[0]);
	return (0);
}
