/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:07:10 by bbehm             #+#    #+#             */
/*   Updated: 2019/12/04 17:11:00 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_connection(char *map, int x)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i + x < 20 + x)
	{
		if (map[i + x] == '#')
		{
			if ((i + x + 1) < (20 + x) && map[i + x + 1] == '#')
				count++;
			if ((i + x - 1) >= x && map[i + x - 1] == '#')
				count++;
			if ((i + x + 5) < (20 + x) && map[i + x + 5] == '#')
				count++;
			if ((i + x - 5) >= x && map[i + x - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int	check_characters(char **map, int x, int y, int amount)
{
	int count;
	int i;

	count = 0;
	while (map && y < amount)
	{
		i = 0;
		if (!(check_connection(map[y], x)))
			return (0);
		while (map[y][x] != '\0' && x < 20)
		{
			if (map[y][x] == '#')
				count++;
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

int	map_validator(char **map)
{
	int y;
	int x;
	int amount;

	x = 0;
	y = 0;
	amount = 0;
	while (map[amount])
		amount++;
	if (!(check_characters(map, x, y, amount)))
		return (0);
	if (y > 25)
		return (0);
	return (1);
}
