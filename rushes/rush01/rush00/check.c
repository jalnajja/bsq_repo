/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalnajja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:21:21 by jalnajja          #+#    #+#             */
/*   Updated: 2025/04/26 12:21:25 by jalnajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

char	*take_row(char matrix[4][4] , int row){
	char	*ptr;
	int	i;
	char	a[5];
	ptr = a;
	i = 0;
	while(i < 5)
	{
		ptr[i] = matrix[row][i];
		i++;
	}
	ptr[4] = '\0';
	return (ptr);
	
}

char	*take_col(char str[4][4], int num)
{
	char	*ptr;
	int	i;
	char	a[5];
	ptr = a;
	i = 0;
	while(i < 5)
	{
		ptr[i] = str[i][num];
		i++;
	}
	ptr[4] = '\0';
	return (ptr);
}

//...................................

int	count_visiable_left_to_right(char *str)
{
	int	i; 
	int	j;
	int	counter;
	int	visible;
	
	i = 3;
	j = 3;
	counter = 0;
	visible = 1;
	
	while (str[i]){
		while(j > 0)
		{
			if (str[i] < str[j - 1])
				visible = 0;
			j--;
		}
		if(visible == 1)
			counter++;
		visible = 1;
		i--;
		j = i;
	}
	return (counter);
}

int	count_visiable_right_to_left(char *str)
{
	int	i; 
	int	j;
	int	counter;
	int	visible;
	
	i = 0;
	j = 0;
	counter = 0;
	visible = 1;
	
	while (str[i]){
		while(j < 4)
		{
			if (str[i] < str[j + 1])
				visible = 0;
			j++;
		}
		if(visible == 1)
			counter++;
		visible = 1;
		i++;
		j = i;
	}
	return (counter);
}
//...................................

int	count_checker_left_rows(char matrix[4][4], char *cases)
{
	int	i;
	int	j;
	int	checker;
	int	count;
	char	*arr;
		
	count = 0;
	j = 0;
	i = 8;
	while (i <= 11)
	{
		arr = take_row(matrix,j);
		checker = count_visiable_left_to_right(arr);
		if(checker == (cases[i] - '0'))
		{
			count++;
		}
		j++;
		i++;
	}
	return count;
}

//...................................

int	count_checker_right_rows(char matrix[4][4], char *cases)
{
	int	i;
	int	j;
	int	checker;
	int	count;
	char	*arr;
	
	count = 0;
	j = 0;
	i = 12;
	
	while (i <= 15)
	{
		arr = take_row(matrix,j);
		checker = count_visiable_right_to_left(arr);
		if(checker == (cases[i] - '0'))
		{
			count++;
		}
		j++;
		i++;
	}
	return count;
}
	
//...................................			
						        //4321122243211222
int	count_checker_top_columns(char matrix[4][4],char *cases)
{
	char	*arr;
	int	i;
	int	checker;
	int	count;
	int	j;
	
	j = 0;
	count = 0;
	i = 0;
	while(i <= 3)
	{
		arr = take_col(matrix,j);
		checker = count_visiable_left_to_right(arr);
		if(checker == (cases[i] - '0'))
		{	
			count++;
		}
		i++;
		j++;
	}
	return count;
}
//...................................		     //4321122243211222

int	count_checker_bot_columns(char matrix[4][4],char *cases)
{
	char	*arr;
	int	i;
	int	checker;
	int	count;
	int	j;
	
	j = 0;
	count = 0;
	i = 4;
	while(i <= 7)
	{
		arr = take_col(matrix,j);
		checker = count_visiable_right_to_left(arr);
		if(checker == (cases[i] - '0'))
		{
			count++;
		}
		i++;
		j++;
	}
	return count;
}



int	overall_validation(char matrix[4][4], char *cases)
{
	int	count_columns;
	int	count_rows;
	int	validation_num;
	
	count_columns = count_checker_bot_columns(matrix,cases) + count_checker_top_columns(matrix,cases);
	count_rows = count_checker_right_rows(matrix,cases) + count_checker_left_rows(matrix,cases);
	validation_num = count_columns + count_rows;
	
	if(validation_num == 16)
		return 1;
	else
		return 0;
}


