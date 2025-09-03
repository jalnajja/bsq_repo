/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalnajja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:31:50 by jalnajja          #+#    #+#             */
/*   Updated: 2025/05/05 14:31:52 by jalnajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_HEADER_H
# define RUSH_HEADER_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	**make_array(int rows, int cols);
char	*get_first_line(char *buffer);
int		**convert_to_int_map(char **arr, int rows, int cols, char empty);
int		*get_size(char *buffer);
int		ft_is_numeric(char c);
int		ft_is_non_conforming_character(char c);
int		ft_atoi(char *str);
int		validate_symbols(char *buffer, int start);
int		validate_cols(char *buffer, int rows);
int		validate_rows(char *buffer, int rows);
int		validate_spy_char(char *buffer, int start, int rows, int cols);
int		full_validation(char *buffer, int start, int rows, int cols);
void	find_biggest_square(int **map, int rows, int cols,
			int *max_size, int *max_i, int *max_j);
void	fill_biggest_square(char **arr, int size, int i, int j, char full);
void	solve_bsq(char **arr, int rows, int cols, char empty, char full);
void	fill_array(char **arr, char *buffer, int start_of_i, int rows);
void	print_sol(char **matrix, int rows, int cols);
#endif
