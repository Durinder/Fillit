/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:37:40 by jhallama          #+#    #+#             */
/*   Updated: 2019/11/27 16:04:43 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 1024
# include "../libft/libft.h"

typedef struct	s_map {
	short	size;
	char	**coordinates;
}				t_map;

typedef struct	s_struct
{
	int		one[2];
	int		two[2];
	int		three[2];
	int		four[2];
	void	*next;
}				t_struct;

char	**create_tetriminos(char *input);
void	tetriminos_into_alphabet(char **tetriminos);
int		map_validator(char **map);
int		list_maker(char **tetrimino, int size);
t_map	new_map(char **tetriminos);

#endif
