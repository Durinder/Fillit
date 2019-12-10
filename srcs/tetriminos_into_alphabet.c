/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_into_alphabet.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:00:43 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/10 11:51:58 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**tetriminos_into_alphabet(char **tetriminos)
{
	char	alpha;
	short	i;
	short	j;

	alpha = 'A';
	i = 0;
	while (tetriminos[i])
	{
		j = 0;
		while (tetriminos[i][j])
		{
			if (tetriminos[i][j] == '#')
				tetriminos[i][j] = alpha;
			j++;
		}
		i++;
		alpha++;
	}
	return (tetriminos);
}
