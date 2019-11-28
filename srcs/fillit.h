/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:37:40 by jhallama          #+#    #+#             */
/*   Updated: 2019/11/28 16:03:51 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 1024
# include "../libft/libft.h"

typedef struct	s_checklist {
	short	dot;
	short	hash;
	short	nl;
}				t_checklist;

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
t_struct	**list_maker(char **tetrimino, int size);
t_map	new_map(char **tetriminos);

#endif
