/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetriminos3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:35:23 by jhallama          #+#    #+#             */
/*   Updated: 2019/11/28 16:14:41 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

void		copy_strings(char **array, char *input)
{
	short	i;
	short	j;
	short	counter;

	i = 0;
	j = 0;
	counter = 0;
	array[i] = ft_strnew(21);
	while (*input)
	{
		if (*input == '\n')
			counter++;
		if (counter != 0 && counter % 5 == 0)
		{
			input++;
			counter++;
			array[i][j] = '\0';
			j = 0;
			array[++i] = ft_strnew(21);
		}
		array[i][j++] = *input++;
	}
	ft_strdel(&array[i]);
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

t_checklist	modify_checklist(char c, t_checklist check)
{
	if (c == '.')
		check.dot++;
	else if (c == '#')
		check.hash++;
	else if (c == '\n')
		check.nl++;
	return (check);
}

short		count_length_check_errors(char *input)
{
	short		i;
	t_checklist	check;

	i = -1;
	check.dot = 0;
	check.hash = 0;
	check.nl = 0;
	while (input[++i])
	{
		if (input[i] != '#' && input[i] != '.' && input[i] != '\n')
			return (0);
		check = modify_checklist(input[i], check);
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
	char	**array;
	short	len;
	short	amount;

	if (!(len = count_length_check_errors(input)))
		return (NULL);
	if (!(amount = count_tetriminos(len)))
		return (NULL);
	if (!(array = (char **)malloc(sizeof(char *) * amount + 1)))
		return (NULL);
	copy_strings(array, input);
	return (array);
}
