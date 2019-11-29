/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:27:03 by jhallama          #+#    #+#             */
/*   Updated: 2019/11/29 17:23:20 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **array)
{
	while (*array)
		ft_putstr(*array++);
}

void	solver(t_map map, t_tetrimino *head)
{	
	t_tetrimino *tmp;
	short	i;
	short	j;

	tmp = head;
	i = 0;
	while (i < map.size)
	{
		j = 0;
		while (j < map.size)
		{
			if (map.xy[i][j] == '.')
			{
				while (tmp->is_placed == 1 && tmp->next != NULL)
					tmp = tmp->next;
				if (tmp->is_placed == 0)
				{
					if (tmp->one[0] + i <= map.size && tmp->one[1] + j <= map.size &&
							tmp->two[0] + i <= map.size && tmp->two[1] + j <= map.size &&
							tmp->three[0] + i <= map.size && tmp->three[1] + j <= map.size &&
							tmp->four[0] + i <= map.size && tmp->four[1] + j <= map.size)
					{
						if (map.xy[i + tmp->one[0]][j + tmp->one[1]] == '.' && 
							map.xy[i + tmp->two[0]][j + tmp->two[1]] == '.' &&
							map.xy[i + tmp->three[0]][j + tmp->three[1]] == '.' &&
							map.xy[i + tmp->four[0]][i + tmp->four[1]] == '.')
						{
							map.xy[i][j] = tmp->alpha;
							map.xy[i + tmp->two[0]][j + tmp->two[1]] = tmp->alpha;
							map.xy[i + tmp->three[0]][j + tmp->three[1]] = tmp->alpha;
							map.xy[i + tmp->four[0]][j + tmp->four[1]] = tmp->alpha;
							tmp->is_placed = 1;
							solver(map, head);
						}
					}
				}
			}
			j++;
		}
		i++;
	}
}
