/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabusnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:53:20 by aabusnin          #+#    #+#             */
/*   Updated: 2025/05/06 12:53:25 by aabusnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

int	min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

int	**convert_to_int_map(char **arr, int rows, int cols, char empty)
{
	int	**int_map;
	int	i;
	int	j;

	int_map = malloc(rows * sizeof(int *));
	i = 0;
	while (i < rows)
	{
		int_map[i] = malloc(cols * sizeof(int));
		j = 0;
		while (j < cols)
		{
			if (arr[i][j] == empty)
				int_map[i][j] = 1;
			else
				int_map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (int_map);
}

void	find_biggest_square(int **map, int rows,
	int cols, int *max_size, int *max_i, int *max_j)
{
	int	i;
	int	j;

	*max_size = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] != 0 && i > 0 && j > 0)
				map[i][j] = 1 + min(map[i - 1][j],
						map[i][j - 1], map[i - 1][j - 1]);
			if (map[i][j] >= *max_size)
			{
				*max_size = map[i][j];
				*max_i = i;
				*max_j = j;
			}
			j++;
		}
		i++;
	}
}

void	fill_biggest_square(char **arr, int size, int i, int j, char full)
{
	int	x;
	int	y;

	x = i;
	while (x > i - size)
	{
		y = j;
		while (y > j - size)
		{
			arr[x][y] = full;
			y--;
		}
		x--;
	}
}

void	solve_bsq(char **arr, int rows, int cols, char empty, char full)
{
	int	**int_map;
	int	max_size;
	int	max_i;
	int	max_j;
	int	i;

	int_map = convert_to_int_map(arr, rows, cols, empty);
	find_biggest_square(int_map, rows, cols, &max_size, &max_i, &max_j);
	fill_biggest_square(arr, max_size, max_i, max_j, full);
	i = 0;
	while (i < rows)
	{
		free(int_map[i]);
		i++;
	}
	free(int_map);
}
