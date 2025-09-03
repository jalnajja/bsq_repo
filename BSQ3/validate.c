/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabusnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:24:38 by aabusnin          #+#    #+#             */
/*   Updated: 2025/05/05 17:24:48 by aabusnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

int	validate_symbols(char *buffer, int start)
{
	char	empty;
	char	obstacle;
	char	full;

	empty = buffer[start];
	obstacle = buffer[start + 1];
	full = buffer[start + 2];
	if (empty == obstacle || empty == full || obstacle == full)
		return (0);
	if (empty <= 32 || obstacle <= 32 || full < 32)
		return (0);
	return (1);
}

int	validate_cols(char *buffer, int rows)
{
	int	i;
	int	count;
	int	*arr;
	int	c_col;

	i = 0;
	count = 0;
	c_col = 0;
	arr = (int *)malloc (sizeof(int) * rows + 1);
	if (arr == NULL)
	{
		write(1, "error in maloc", 15);
		exit(1);
	}
	while (buffer[i])
	{
		if (buffer[i] != '\n')
		{
			count++;
		}
		else if (buffer[i] == '\n')
		{
			arr[c_col] = count;
			count = 0;
			c_col++;
		}
		i++;
	}
	i = 1;
	while (i < (rows))
	{
		if (arr[i] != arr[i + 1])
			return (0);
		i++;
	}
	free(arr);
	return (1);
}

int	validate_rows(char *buffer, int rows)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			count++;
		i++;
	}
	count = count - 1;
	if (count != rows)
	{
		write (1, "error in rows validation", 25);
		return (0);
	}
	return (1);
}

int	validate_spy_char(char *buffer, int start, int rows, int cols)
{
	char	empty;
	char	obstacle;
	char	full;
	int		i;

	empty = buffer[start];
	obstacle = buffer[start + 1];
	full = buffer[start + 2];
	i = start;
	while (i < ((rows * cols) + start + 4))
	{
		if ((buffer[i] != empty) && (buffer[i] != obstacle)
			&& (buffer[i] != full) && (buffer[i] != '\n')
			&& (buffer[i] != '\0'))
		{
			write(1, "error in characters", 25);
			return (0);
		}
		i++;
	}
	return (1);
}

int	full_validation(char *buffer, int start, int rows, int cols)
{
	int	sum;

	sum = validate_symbols(buffer, start)
		+ validate_cols(buffer, rows) + validate_rows(buffer, rows)
		+ validate_spy_char(buffer, start, rows, cols);
	if (sum == 4)
		return (1);
	return (0);
}
