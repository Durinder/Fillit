/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:37:40 by jhallama          #+#    #+#             */
/*   Updated: 2019/11/25 19:02:14 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 1024
# include "../libft/libft.h"

char	**create_tetriminos(char *input);
int		ft_map_validator(char **map);

#endif
