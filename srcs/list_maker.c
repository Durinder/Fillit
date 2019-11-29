/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:31:54 by jhallama          #+#    #+#             */
/*   Updated: 2019/11/29 15:16:26 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

t_tetrimino	*create_piece()
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
	piece->alpha = '#';
	piece->next = NULL;
	return (piece);
}

void	push_back_piece(t_tetrimino *head)
{
	t_tetrimino	*new_piece;
	t_tetrimino	*current;

	new_piece = create_piece();
	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_piece;
}

t_tetrimino *tetriminos_into_list(char **tetriminos)
{
	t_tetrimino	*head;
	short		i;

	head = create_piece();
	i = 0;
	while (tetriminos[i])
	{
		push_back_piece(head);
		i++;
	}
	return (head);
}
