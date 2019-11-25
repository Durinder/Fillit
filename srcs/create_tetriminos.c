/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetriminos3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:35:23 by jhallama          #+#    #+#             */
/*   Updated: 2019/11/25 18:35:20 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	copy_strings(char **array, char *input)
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

short	count_tetriminos(short len)
{
	if (len > 545)
		return (0);
	if (len >= 440)
		return ((len / 4 / 5) - 1);
	else
		return (len / 4 / 5);
}

short	count_length_check_errors(char *input)
{
	short	len;

	len = 0;
	while (input[len] != '\0')
	{
		if (input[len] != '#' && input[len] != '.' && input[len] != '\n')
			return (0);
		if (len != 0 && (len - 20) % 21 == 0 && input[len] != '\n')
		{
			return (0);
		}
		len++;
	}
	return (len);
}

char	**create_tetriminos(char *input)
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
