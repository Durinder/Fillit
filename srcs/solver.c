/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:27:03 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/02 18:24:39 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	print_map(char **array)
{
	while (*array)
		ft_putstr(*array++);
}

int		solver(t_map map, t_tetrimino *head)
{	
	t_tetrimino *tmp;
	short	i;
	short	j;

	tmp = head;
	i = 0;
	while (tmp != NULL)
	{
		ft_putchar(tmp->alpha);
		ft_putnbr(tmp->one[0]);
		ft_putnbr(tmp->one[1]);
		ft_putnbr(tmp->two[0]);
		ft_putnbr(tmp->two[1]);
		ft_putnbr(tmp->three[0]);
		ft_putnbr(tmp->three[1]);
		ft_putnbr(tmp->four[0]);
		ft_putnbr(tmp->four[1]);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	tmp = head;
	while (i < map.size)
	{
		j = 0;
		while (j < map.size)
		{
			if (map.xy[i][j] == '.')
			{
				while (tmp->is_placed == 1 && tmp->next != NULL)
					tmp = tmp->next;
	//			ft_putchar(tmp->alpha);
				if (tmp->is_placed == 0)
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
					//		print_map(map.xy);
							solver(map, head);
							return (0);
						}
					}
				}
			}
			j++;
		}
		i++;
	}
	tmp = head;
	while (tmp->is_placed == 1 && tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	if (tmp->is_placed == 0)
	{
		ft_putendl("new map");
		map.xy = create_map(map.size += 1);
		tmp = head;
		while (tmp->next != NULL)
		{
			if (tmp->is_placed == 1) // TAA ON VIRHEELLINEN!
				solver(map, head); // TAA ON VIRHEELLINEN!
			tmp->is_placed = 0;
			tmp = tmp->next;
		}
		solver(map, head);
		return (0);
	}
	print_map(map.xy);
	return (0);
}
