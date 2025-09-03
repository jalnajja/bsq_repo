/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalnajja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:00:51 by jalnajja          #+#    #+#             */
/*   Updated: 2025/04/26 15:00:53 by jalnajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	overall_validation(char matrix[4][4], char *cases);
char	*take_row(char matrix[4][4], int row);
char	*take_col(char str[4][4], int num);

void insertrow_to(char *str, int row, char matrix[4][4])
{
	int	i;
	i = 0;
	
	while ( i < 4)
	{
		matrix[row][i] = str[i];
		i++;
	}
	
}

int is_found(char *s,char choise){
	int	i;
	i = 0;
	while (s[i]){
		if(choise == s[i])
			return (1);
		i++;
	}
	return (0);	
}

int is_repeted(char *s){
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while ( i < 4){
		while ( j < 3){
			if(s[i] == s[j + 1])
				return (1);
			j++;
		}
	j = i + 1;
	i++;
	}
	return (0);	
}

void	ft_swap(char *a, char *b)
{
	int	x;

	x = *a;
	*a = *b;
	*b = x;
}

void print_sol(char matrix[4][4]){
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			write(1,&matrix[i][j],1);
			write(1," ",1);
			j++;
		}
		write(1,"\n",1);
		j = 0;
		i++;
	}
	write(1,"\n",1);
}


void solve(char *input){
	int	i;
	int	j;
	char	a[4][4];
	char	choise;
	int	k;

	i = 0;
	j = 0;
	choise = '1';
	while ( i < 4)
	{
		while (j < 4)
		{
			while (1){
				if (!is_found(take_row(a,i),choise) && !is_found(take_col(a,j),choise))
				{
					//printf("\n%s","in if");
					a[i][j] = choise;
					break;
				}
				if( choise == '4')
					choise = '1';
				else 
					choise ++;
				}
			choise = '1';
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	k = 0;
	//int x = 0;
	while (1)
	{
		if (overall_validation(a,input))
		{
			print_sol(a);
			return;
		}
		i = 0;
		while (i < 4)
		{
			while (j < 4)
			{
				while ( 1)
				{
					if (k%2 == 0)
					{

						ft_swap(&a[i][j], &a[i][j + 1]);
						k++;
						if (!is_repeted(take_col(a,0)) && !is_repeted(take_col(a,1))
					&& !is_repeted(take_col(a,2)) && !is_repeted(take_col(a,3)))
						break;
					}
					else 
					{
						ft_swap(&a[i][j], &a[i][j + 2]);
						k++;
						if (!is_repeted(take_col(a,0)) && !is_repeted(take_col(a,1))
					&& !is_repeted(take_col(a,2)) && !is_repeted(take_col(a,3)))
						break;
					}
				print_sol(a);
				}
				

			 }
			j++;
		}
		j = 0;
		i++;
		print_sol(a);
		
		}
	
}

int	main(int argc , char **argv)
{
	char *str;
	char s[17];
	int i;
	int j;
	
	str = argv[1];
	i = 0;
	j = 0;
	if(argc ==2)
	{
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if ( str[i] <= '4' && str[i] >= '1')
		{
			s[j] = str[i];
			i++;
			j++;
		}
		else
		{
			write(1,"not valid input",15);
			break;
		}
	}
	s[16] = '\0';
	
	if( j != 16 )
		write(1,"need 16 numbers",15);
	

	solve(s);
	
	//char arr[4][4] =
	//{{'1', '2', '3', '4'},
	//{'2', '3', '4', '1'},
	//{'3', '4', '1', '2'},
	//{'4', '1', '2', '3'}};
	 
	//printf("%d",is_repeted(take_row(arr,0),'1'));
	//printf("\n%d",is_repeted(take_col(arr,0),'1'));
	//printf("\n%d",overall_validation(arr,s));
	
	//solve();
	//print_sol(arr);
	//print_sol(arr);
	//print_sol(arr);
	//ft_swap(&arr[0][0],&arr[0][3] );
	//print_sol(arr);
	
	//printf("%d",is_repeted("1443"));
	}
}
