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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/*char *read_grid(char *path)
{
	char *ptr;
	int fd = open(path , O_RDONLY); 
	if (fd < 0)
	{
        	printf("\nError Opening File!!\n");
        	exit(1);
   	}
	char buffer[1024];

	int bytesRead = read(fd, buffer, sizeof(buffer));
	if (close(fd) < 0) {
        	printf("\nError in closing File!!\n");
		exit(1);
	}
	ptr = buffer;
	return (ptr);
}*/
//......................................
int	ft_is_numeric(char c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

int	ft_is_non_conforming_character(char c)
{
	if (!ft_is_numeric(c) && !((c >= 9 && c <= 13)
			|| c == 32) && !(c == '-') && !(c == '+'))
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	r;
	int	sign;

	i = 0;
	r = 0;
	sign = 1;
	while (str[i])
	{
		if (str[i] == '-')
			sign = sign * -1;
		if (ft_is_numeric(str[i]))
			r = r * 10 + (str[i] - 48);
		if (ft_is_non_conforming_character(str[i]))
			return (sign * r);
		i++;
	}
	return (sign * r);
}
//...............................................
char **make_array(int cols, int rows)
{
	int	i;
	i = 0;
	//printf("number of columns: %d\n", cols);
	//printf("number of rows: %d\n",rows);
	char **arr = malloc(rows * sizeof(char*));
	while (i < rows)
	{
		arr[i] = malloc(cols * sizeof(char));
		i++;
	}
	return (arr);
}
//...............................................
void fill_array(char** arr,char* buffer, int start_of_i, int rows)
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
			//printf("%d %d",row,col);
			write(1,&buffer[i],1);
			//printf("%s","\n");
			arr[row][col] = buffer[i];
			col++;
			i++;
		}
		write(1,"\n",1);
		row ++;
		col = 0;
		i++;
		j++;
	}
}
//.......................................
/*char *get_data(char *buffer)
{
	
}*/


void print_sol(char **matrix , int rows, int cols){
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < rows)
	{
		while (j < cols)
		{
			write(1,&matrix[i][j],1);
			j++;
		}
		write(1,"\n",1);
		j = 0;
		i++;
	}
	write(1,"\n",1);
}

int main (int argc , char *argv[])
{
	int	i;
	//.........reading the whole file.........
	char *path = argv[1];
	int fd = open(path , O_RDONLY); 
	if (fd < 0)
	{
        	printf("\nError Opening File!!\n");
        	exit(1);
   	}
	char buffer[1024];

	int bytesRead = read(fd, buffer, sizeof(buffer));
	if (close(fd) < 0) {
        	printf("\nError in closing File!!\n");
		exit(1);
	}
	
	//printf("%d bytes read!\n", bytesRead);
	//printf("File Contents: %s\n", buffer);
	//........get data........
	i = 0;
	char *number;
	while (buffer[i] >= '0' && buffer[i] <= '9')
	{
		number[i] = buffer[i];
		i++;
	}
	printf("%d",i);
	printf("%s",number);
	
	//.............making the 2d array ...........
	int	 cols;
	cols = 5;
	int	rows;
	rows = buffer[0] - '0';
	
	while (buffer[cols] != '\n')
		cols++;
	cols -= 5;
	char **arr;
	arr = make_array(rows,cols);
	//printf("number of columns: %d\n", cols);
	//printf("number of rows: %d\n",rows);

	//.....filling the aray and taking the first line......
	char empty;
	char obstacle;
	char full;
	empty = buffer[1];
	obstacle = buffer[2];
	full = buffer[3];
	//printf("%c%c%c\n",empty,obstacle,full);
	i = 5;
	fill_array(arr,buffer,i,rows);
	write(1,"\n",1);
	print_sol(arr, rows , cols);
    return 0;
}
