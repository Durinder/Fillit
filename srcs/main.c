/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:07:05 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/02 16:50:08 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	**tetriminos;
	char	buf[BUFF_SIZE + 1];
	int		fd;
	int		ret;
	t_map	map;
	short	i;
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
		//list = *list_maker(tetriminos, 4);
		ft_putendl("Solver is not done yet!");
	}
	i = 0;
	while (tetriminos[i])
	{
		ft_putendl(tetriminos[i]);
		i++;
	}
	map = new_map(tetriminos);
	i = 0;
	while (map.xy[i])
	{
		ft_putstr(map.xy[i]);
		i++;
	}
	head = tetriminos_into_list(tetriminos);

//	while (head)
//	{
//		ft_putnbr(head->is_placed);
//		head = head->next;
//	}
//	while (head)
//	{
//		ft_putnbr(head->one[0]);
//		ft_putnbr(head->one[1]);
//		ft_putnbr(head->two[0]);
//		ft_putnbr(head->two[1]);
//		ft_putnbr(head->three[0]);
//		ft_putnbr(head->three[1]);
//		ft_putnbr(head->four[0]);
//		ft_putnbr(head->four[1]);
//		head = head->next;
//	}
	solver(map, head);
//	while (1) {};
	return (0);
}
