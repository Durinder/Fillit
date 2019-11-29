/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:58:11 by jhallama          #+#    #+#             */
/*   Updated: 2019/11/29 17:07:44 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(short size)
{
	char	**array;
	short	i;
	short	j;
	
	array = (char **)malloc(sizeof(char *) * size + 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		array[i] = (char *)malloc(sizeof(char) * size + 2);
		while (j < size)
			array[i][j++] = '.';
		array[i][j++] = '\n';
		array[i][j] = '\0';
		i++;
	}
	array[i] = NULL;
	return (array);
}

short	smallest_square(char **tetriminos)
{
	short	i;
	short	amount;

	i = 0;
	amount = 0;
	while (tetriminos[i])
	{
		amount++;
		i++;
	}
	i = 0;
	while (i * i < amount * 4)
		i++;
	return (i);
}

t_map	new_map(char **tetriminos)
{
	t_map	map;

	map.size = smallest_square(tetriminos);
	map.xy = create_map(map.size);
	return (map);
}
