/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:27:03 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/05 18:17:11 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	print_map(char **array)
{
	while (*array)
		ft_putstr(*array++);
	printf("\n\n");
}

char	**save_map(t_map map)
{
	char			**array;
	short			i;
	short			j;

	array = create_map(map.size);
	i = 0;
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

void	retrieve_map(t_map src, t_map dst)
{
	short			i;

	i = 0;
	while (src.xy[i])
	{
		dst.xy[i] = ft_strcpy(dst.xy[i], src.xy[i]);
		i++;
	}
}

int		place_piece(t_map map, t_tetrimino *tmp, short i, short j)
{
	if (tmp->one[0] + i < map.size && tmp->one[1] + j < map.size &&
			tmp->two[0] + i < map.size && tmp->two[1] + j < map.size &&
			tmp->three[0] + i < map.size && tmp->three[1] + j < map.size &&
			tmp->four[0] + i < map.size && tmp->four[1] + j < map.size /*&&
			tmp->one[0] + i >= 0 && tmp->one[1] + j >= 0 &&
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

/*	short	i;
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
	if (node->alpha == alpha - 1 && node->is_placed == 1)
	{
		print_map(map.xy);
		return (1);
	}*/
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
				save.xy = save_map(map);
				print_map(save.xy);
				current = head;
				while (current->is_placed == 1 && current->next != NULL)
					current = current->next;
				if (place_piece(map, current, i, j) == 1)
				{
					if (check_solution(head, map) != 1)
					{
						if (solver(map, head) != 1)
						{
							current->is_placed = 0;
							retrieve_map(save, map);
					//		ft_putendl("map retrieved");
						}
						else
							return (1);
					}
					else
						return (1);
				}
			}
			j++;
		}
		i++;
	}
	//ft_putendl("vituiks man");
/*	ft_putendl("hello");	
	while (current->next != NULL)
		current->is_placed = 0;
	map.xy = create_map(map.size += 1);
	ft_putendl("miksi");
	solver(map, head);*/
	return (0);
}
