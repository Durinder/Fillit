/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:07:05 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/10 12:08:51 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
#include <fcntl.h>

void	send_valid_to_solver(char **tetriminos)
{
	t_map		map;
	t_tetrimino	*head;
	t_tetrimino	*current;

	map = new_map(tetriminos);
	head = tetriminos_into_list(tetriminos);
	while (solver(map, head, -1, -1) == 0)
	{
		free_map(map);
		map.size++;
		map.xy = create_map(map.size);
	}
	free_map(map);
	while (head != NULL)
	{
		current = head;
		head = current->next;
		free(current);
	}
}

char	**reader(char **tetriminos, char *input)
{
	char	buf[BUFF_SIZE + 1];
	int		fd;
	int		ret;

	fd = open(input, O_RDONLY);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	ret = close(fd);
	tetriminos = create_tetriminos(buf);
	if (tetriminos == NULL)
	{
		ft_putendl("error");
		exit(1);
	}
	return (tetriminos);
}

int		main(int argc, char **argv)
{
	char	**tetriminos;

	tetriminos = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [file_with_tetriminos]\n");
		exit(1);
	}
	else
		tetriminos = reader(tetriminos, argv[1]);
	if (!(map_validator(tetriminos)))
	{
		ft_putendl("error");
		exit(1);
	}
	send_valid_to_solver(tetriminos_into_alphabet(tetriminos));
	while (1) { };
	return (0);
}
