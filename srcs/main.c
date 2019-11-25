/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:07:05 by jhallama          #+#    #+#             */
/*   Updated: 2019/11/25 19:00:49 by bbehm            ###   ########.fr       */
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
			ft_putendl("error");
			return (0);
		}
	}
	int i = 0;
	while (tetriminos[i])
	{
		ft_putendl(tetriminos[i]);
		i++;
	}
	if (!(ft_map_validator(tetriminos)))
		ft_putendl("error");
	//while (1) {};
	return (0);
}
