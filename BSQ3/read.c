/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalnajja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:31:45 by jalnajja          #+#    #+#             */
/*   Updated: 2025/05/05 14:31:46 by jalnajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

char	**make_array(int rows, int cols)
{
	char	**arr;
	int		i;

	i = 0;
	arr = malloc (rows * sizeof(char *));
	while (i < rows)
	{
		arr[i] = malloc(cols * sizeof(char));
		i++;
	}
	return (arr);
}

void	fill_array(char **arr, char *buffer, int start_of_i, int rows)
{
	int	j;
	int	i;
	int	col;
	int	row;

	row = 0;
	col = 0;
	j = 0;
	i = start_of_i;
	while (j < rows)
	{
		while (buffer[i] != '\n')
		{
			arr[row][col] = buffer[i];
			col++;
			i++;
		}
		row ++;
		col = 0;
		i++;
		j++;
	}
}

int	*get_size(char *buffer)
{
	char	number[10];
	int		*p;
	int		start;
	int		cols;
	int		rows;

	p = malloc (3 * sizeof (int));
	start = 0;
	while (buffer[start] >= '0' && buffer[start] <= '9')
	{
		number[start] = buffer[start];
		start++;
	}
	cols = start + 4;
	rows = ft_atoi(number);
	while (buffer[cols] != '\n')
		cols++;
	cols -= (start + 4);
	p[0] = rows;
	p[1] = cols;
	p[2] = start;
	return (p);
}
