/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:07:05 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/09 15:40:02 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**tetriminos;
	char	buf[BUFF_SIZE + 1];
	int		fd;
	int		ret;
	t_map	map;
	t_tetrimino	*head;

	if (argc != 2)
	{
		//display usage!
		return (0);
	}
	else
	{
		tetriminos = NULL;
		fd = open(argv[1], O_RDONLY);
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		ret = close(fd);
		tetriminos = create_tetriminos(buf);
		if (tetriminos == NULL)
		{
			ft_putendl("create_tetriminos error");
			return (0);
		}
	}
	if (!(map_validator(tetriminos)))
		ft_putendl("HERE error");
	else
	{
		tetriminos_into_alphabet(tetriminos);
		ft_putendl("Solver is not done yet!");
	}
	map = new_map(tetriminos);
	head = tetriminos_into_list(tetriminos);
	while (solver(map, head, -1, -1) == 0)
	{
		int xd = 0;
		while (xd < map.size)
		{
			free(map.xy[xd]);
			xd++;
		}
		map.xy = NULL;
		map.size++;
		map.xy = create_map(map.size);
		printf("%d\n", map.size);
	}
	while (1) {};
	return (0);
}
