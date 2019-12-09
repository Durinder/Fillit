/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:27:03 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/09 15:46:01 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_map(t_map map)
{
	short	i;

	i = 0;
	while (map.xy[i])
		ft_strdel(&map.xy[i++]);
	free(map.xy);
}

int		place_piece(t_map map, t_tetrimino *tmp, short i, short j)
{
	if (tmp->one[0] + i < map.size && tmp->one[1] + j < map.size &&
			tmp->two[0] + i < map.size && tmp->two[1] + j < map.size &&
			tmp->three[0] + i < map.size && tmp->three[1] + j < map.size &&
			tmp->four[0] + i < map.size && tmp->four[1] + j < map.size)
	{
		if (map.xy[i + tmp->one[0]][j + tmp->one[1]] == '.' &&
			map.xy[i + tmp->two[0]][j + tmp->two[1]] == '.' &&
			map.xy[i + tmp->three[0]][j + tmp->three[1]] == '.' &&
			map.xy[i + tmp->four[0]][j + tmp->four[1]] == '.')
		{
			map.xy[i + tmp->one[0]][j + tmp->one[1]] = tmp->alpha;
			map.xy[i + tmp->two[0]][j + tmp->two[1]] = tmp->alpha;
			map.xy[i + tmp->three[0]][j + tmp->three[1]] = tmp->alpha;
			map.xy[i + tmp->four[0]][j + tmp->four[1]] = tmp->alpha;
			tmp->is_placed = 1;
			return (1);
		}
	}
	return (0);
}

int		check_solution(t_tetrimino *node, t_map map)
{
	char	alpha;

	alpha = 'A';
	while (node->next != NULL)
	{
		alpha++;
		node = node->next;
	}
	if (node->alpha == alpha && node->is_placed == 1)
	{
		print_map(map.xy);
		return (1);
	}
	return (0);
}

int		magic(t_map map, t_map save, t_tetrimino *head, t_tetrimino *current)
{
	if (check_solution(head, map) != 1)
	{
		if (solver(map, head, -1, -1) != 1)
		{
			current->is_placed = 0;
			retrieve_map(save, map);
		}
		else
		{
			free_map(save);
			return (1);
		}
	}
	else
	{
		free_map(save);
		return (1);
	}
	return (0);
}

int		solver(t_map map, t_tetrimino *head, short i, short j)
{
	t_tetrimino *current;
	t_map		save;

	save.xy = NULL;
	while (++i < map.size)
	{
		j = -1;
		while (++j < map.size)
		{
			if (map.xy[i][j] == '.')
			{
				save.xy = save_map(map, save);
				current = head;
				while (current->is_placed == 1 && current->next != NULL)
					current = current->next;
				if (place_piece(map, current, i, j) == 1)
					if (magic(map, save, head, current) == 1)
						return (1);
			}
		}
	}
	free_map(save);
	return (0);
}
