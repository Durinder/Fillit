/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:31:54 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/02 16:42:31 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

static t_tetrimino	*create_piece(short i)
{
	t_tetrimino	*piece;
	
	if (!(piece = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
		return (NULL);
	piece->is_placed = 0;
	piece->one[0] = 0;
	piece->one[1] = 0;
	piece->two[0] = 0;
	piece->two[1] = 0;
	piece->three[0] = 0;
	piece->three[1] = 0;
	piece->four[0] = 0;
	piece->four[1] = 0;
	piece->alpha = 'A' + i;
	piece->next = NULL;
	return (piece);
}

static void	push_back_piece(t_tetrimino *head, short i)
{
	t_tetrimino	*new_piece;
	t_tetrimino	*current;

	new_piece = create_piece(i);
	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_piece;
}

static void fill_more(t_tetrimino *head, int info[4][2], short i)
{
	while (i > 0)
	{
		head = head->next;
		i--;
	}
	head->one[0] = (info[0][0] - info[0][0]);
	head->one[1] = (info[0][1] - info[0][1]);
	head->two[0] = (info[1][0] - info[0][0]);
	head->two[1] = (info[1][1] - info[0][1]);
	head->three[0] = (info[2][0] - info[0][0]);
	head->three[1] = (info[2][1] - info[0][1]);
	head->four[0] = (info[3][0] - info[0][0]);
	head->four[1] = (info[3][1] - info[0][1]);
	/*ft_putnbr(head->one[0]);
	ft_putnbr(head->one[1]);
	ft_putnbr(head->two[0]);
	ft_putnbr(head->two[1]);
	ft_putnbr(head->three[0]);
	ft_putnbr(head->three[1]);
	ft_putnbr(head->four[0]);
	ft_putnbr(head->four[1]);*/
}

#include <stdio.h>
static void fill_piece(t_tetrimino *head, char *tetri, short i)
{
	int x;
	int info[4][2];
	int a;
	int y;

	x = 0;
	a = 0;
	y = 0;
	while (x < 19)
	{
		while (x < 19 && (tetri[x] > 'Z' || tetri[x] < 'A'))
		{
			if (tetri[x] == '\n')
				y++;
			x++;
		}
		if (x < 19 && tetri[x] >= 'A' && tetri[x] <= 'Z')
		{
			info[a][0] = y;
			info[a][1] = x % 5;
			a++;
			x++;
		}
	}
	fill_more(head, info, i);
}

t_tetrimino *tetriminos_into_list(char **tetriminos)
{
	t_tetrimino	*head;
	short		i;

	i = 0;
	head = create_piece(i);
	fill_piece(head, tetriminos[i], i);
	i++;
	while (tetriminos[i])
	{
		push_back_piece(head, i);
		fill_piece(head, tetriminos[i], i);
		i++;
	}
	ft_strdel(tetriminos);
	return (head);
}
