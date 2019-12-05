/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:27:03 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/05 13:43:23 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	print_map(char **array)
{
	while (*array)
		ft_putstr(*array++);
}

char	**save_map(t_map map)
{
	char	**array;
	short	i;
	short	j;

	array = create_map(map.size);
	i = 0;
	j = 0;
	while (i < map.size)
	{
		j = 0;
		while (j < map.size)
		{
			array[i][j] = map.xy[i][j];
			j++;
		}
		i++;
	}
	return (array);
}

int		place_piece(t_map map, t_tetrimino *tmp, short i, short j)
{
	if (tmp->one[0] + i < map.size && tmp->one[1] + j < map.size &&
			tmp->two[0] + i < map.size && tmp->two[1] + j < map.size &&
			tmp->three[0] + i < map.size && tmp->three[1] + j < map.size &&
			tmp->four[0] + i < map.size && tmp->four[1] + j < map.size// &&
		/*	tmp->one[0] + i >= 0 && tmp->one[1] + j >= 0 &&
			tmp->two[0] + i >= 0 && tmp->two[1] + j >= 0 &&
			tmp->three[0] + i >= 0 && tmp->three[1] + j >= 0 &&
			tmp->four[0] + i >= 0 && tmp->four[1] + j >= 0*/)
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
	//		ft_putendl("piece placed");
			return (1);
		}
	}
	return (0);
}

int		check_solution(t_tetrimino *node, t_map map)
{
	short	i;
	short	j;
	char	alpha;

	i = 0;
	alpha = 'A';
	while (i < map.size)
	{
		j = 0;
		while (j < map.size)
		{
			if (map.xy[i][j] == alpha)
			{
				alpha++;
				i = 0;
				j = 0;
			}
			j++;
		}
		i++;
	}
	while (node->next != NULL)
		node = node->next;
	if (node->alpha == alpha && node->is_placed == 1)
	{
		print_map(map.xy);
		return (1);
	}
	return (0);
}

int		solver(t_map map, t_tetrimino *head/*, short i, short j*/)
{
	t_tetrimino *current;
	t_map		save;
	short		i;
	short		j;
	
	i = 0;
	while (i < map.size)
	{
		j = 0;
		while (j < map.size)
		{
			if (map.xy[i][j] == '.')
			{
				current = head;
				while (current->is_placed == 1 && current->next != NULL)
					current = current->next;
				save.xy = save_map(map);
				if (place_piece(map, current, i, j) == 1)
				{
					if (solver(map, head) != 1)
					{
						current->is_placed = 0;
						solver(save, head);
					}
				}
			}
			j++;
		}
		i++;
	}
	if (check_solution(current = head, map) == 1)
	{
		ft_putendl("here?");
		return (1);
	}
	map.xy = create_map(map.size += 1);
	current = head;
	while (current->next != NULL)
	{
		current->is_placed = 0;
		current = current->next;
		solver(map, head);
	}
	return (0);
}
