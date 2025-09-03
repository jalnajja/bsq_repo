/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalnajja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:43:30 by jalnajja          #+#    #+#             */
/*   Updated: 2025/05/04 20:43:32 by jalnajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

void	print_sol(char **matrix, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		while (j < cols)
		{
			write(1, &matrix[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	char	**arr;
	char	*path;
	char	buffer[15000];
	char	empty;
	char	obstacle;
	char	full;
	int		*p;
	int		c;
	int		start;
	int		cols;
	int		rows;
	int		fd;
	int		i;

	c = 1;
	while (c < argc)
	{
		path = argv[c];
		fd = open(path, O_RDONLY);
		if (fd < 0)
		{
			write(1, "\nError Opening File!!\n", 23);
			exit(1);
		}
		read(fd, buffer, sizeof(buffer));
		if (close(fd) < 0)
		{
			write(1, "\nError in closing File!!\n", 26);
			exit(1);
		}
		p = get_size(buffer);
		start = p[2];
		cols = p[1];
		rows = p[0];
		if (full_validation(buffer, start, rows, cols))
		{
			arr = make_array(rows, cols);
			empty = buffer[start];
			obstacle = buffer[start + 1];
			full = buffer[start + 2];
			fill_array(arr, buffer, start + 4, rows);
			solve_bsq(arr, rows, cols, empty, full);
			print_sol(arr, rows, cols);
			i = 0;
			while (buffer[i])
			{
				buffer[i] = '0';
				i++;
			}
			free(arr);
			free(p);
		}
		c++;
	}
	return (0);
}
