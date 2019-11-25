/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:07:10 by bbehm             #+#    #+#             */
/*   Updated: 2019/11/25 12:04:28 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_map_validator(char **map)
{
	int y;
	int x;
	int count;

	x = 0;
	y = 0;
	count = 0;
	while (map)
	{
		while (map[y])
		{
			if (map[y][x] != '.' && map[y][x] != '#' && map[y][x] != '\n')
				return (-1);
			if (map[y][x] == '#' && x < 14 && x > 4)
			{
				count++;
				if ((x < 14 && x > 4) && (map[y][x + 1] != '#' &&
							map[y][x - 1] != '#' && map[y][x + 5] != '#' &&
							map[y][x - 5] != '#'))
					return (-1);
				else if ((x > 14) && (map[y][x + 1] != '#' && map[y][x - 1]
							!= '#' && map[y][x - 5] != '#'))
					return (-1);
				else if ((x < 5) && (map[y][x + 1] != '#' && map[y][x - 1]
							!= '#' && map[y][x + 5] != '#'))
					return (-1);
			}
			x++;
		}
		if (count != 4)
			return (-1);
		count = 0;
		x = 0;
		y++;
	}
	if (y > 25)
		return (-1);
	return (0);
}
