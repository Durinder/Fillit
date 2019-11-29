/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetriminos3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:35:23 by jhallama          #+#    #+#             */
/*   Updated: 2019/11/29 15:09:29 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

void		null_terminator(char **array, short counter, short i)
{
	if (counter == 4)
	{
		array[0][21] = '\0';
		array[1] = ft_strnew(0);
		ft_strdel(&array[1]);
	}
	else
		ft_strdel(&array[i]);
}

void		copy_strings(char **array, char *input, short counter)
{
	short	i;
	short	j;

	i = 0;
	j = 0;
	array[i] = ft_strnew(21);
	while (*input)
	{
		if (*input == '\n')
			counter++;
		if ((counter != 0 && counter % 5 == 0))
		{
			input++;
			counter++;
			array[i][j] = '\0';
			j = 0;
			array[++i] = ft_strnew(21);
		}
		array[i][j++] = *input++;
	}
	null_terminator(array, counter, i);
}

short		count_tetriminos(short len)
{
	if (len > 545)
		return (0);
	if (len >= 440)
		return ((len / 4 / 5) - 1);
	else
		return (len / 4 / 5);
}

short		count_length_check_errors(char *input, t_checklist check)
{
	short		i;

	i = -1;
	while (input[++i])
	{
		if (input[i] == '.')
			check.dot++;
		else if (input[i] == '#')
			check.hash++;
		else if (input[i] == '\n')
			check.nl++;
		if (input[i] != '#' && input[i] != '.' && input[i] != '\n')
			return (0);
		if (check.nl == 4 || input[i + 1] == '\0')
		{
			if (check.dot != 12 || check.hash != 4 || (input[i + 1]
					!= '\n' && input[i + 1] != '\0'))
				return (0);
			check.nl = -1;
			check.dot = 0;
			check.hash = 0;
		}
	}
	return (i);
}

char		**create_tetriminos(char *input)
{
	char		**array;
	short		len;
	short		amount;
	short		counter;
	t_checklist	check;

	check.dot = 0;
	check.hash = 0;
	check.nl = 0;
	if (!(len = count_length_check_errors(input, check)))
		return (NULL);
	if (!(amount = count_tetriminos(len)))
		return (NULL);
	if (!(array = (char **)malloc(sizeof(char *) * amount + 1)))
		return (NULL);
	copy_strings(array, input, counter = 0);
	return (array);
}
