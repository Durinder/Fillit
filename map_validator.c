/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:07:10 by bbehm             #+#    #+#             */
/*   Updated: 2019/11/25 17:15:01 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_check_neighbours(char *map, int x, int y)
{
	if (x < 14 && x > 4)
	{
		if (map[x + 1] != '#' && map[x - 1] != '#' && map[x + 5] != '#'
				&& map[x - 5] != '#')
			return (0);
	}
	else if (x > 14)
	{
		if (map[x + 1] != '#' && map[x - 1] != '#' && map[x - 5] != '#')
			return (0);
	}
	else if (x < 5 && x > 0)
	{
		if (map[x + 1] != '#' && map[x - 1] != '#' && map[x + 5] != '#')
			return (0);
	}
	else if (x == 0)
	{
		if (map[x + 1] != '#' && map[x + 5] != '#')
			return (0);
	}
	return (1);
}

int	ft_characters(char **map, int x, int y, int amount)
{
	int count;

	count = 0;
	while (map && y < amount)
	{
		while (map[y][x] != '\0' && x < 19)
		{
			if (map[y][x] == '#')
			{
				count++;
				if (!(ft_check_neighbours(map[y], x, y)))
					return (0);
			}
			x++;
		}
		if (count != 4)
			return (0);
		count = 0;
		x = 0;
		y++;
	}
	return (1);
}

int	ft_map_validator(char **map)
{
	int y;
	int x;
	int amount;

	x = 0;
	y = 0;
	amount = 2;
	if (!(ft_characters(map, x, y, amount)))
		return (0);
	if (y > 25)
		return (0);
	return (1);
}
