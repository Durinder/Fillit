/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:37:40 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/02 17:03:08 by jhallama         ###   ########.fr       */
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
	char	**xy;
}				t_map;

typedef struct	s_tetrimino {
	short				is_placed;
	int					one[2];
	int					two[2];
	int					three[2];
	int					four[2];
	char				alpha;
	struct s_tetrimino	*next;
}				t_tetrimino;



char			**create_tetriminos(char *input);
void			tetriminos_into_alphabet(char **tetriminos);
int				map_validator(char **map);
t_map			new_map(char **tetriminos);
char			**create_map(short size);
t_tetrimino		*tetriminos_into_list(char **tetriminos);
int				solver(t_map map, t_tetrimino *head);
void			print_map(char **array);

#endif
