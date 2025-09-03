/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-majd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:44:33 by oal-majd          #+#    #+#             */
/*   Updated: 2025/04/18 23:09:48 by oal-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	firstline(int a)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	if (x == 1 && y == 1)
	{
		ft_putchar('A');
	}
	while (x < a)
	{
		ft_putchar('B');
		x++;
	}
	if (x == a && y == 1)
	{
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	lastline(int a)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	if (x == 1 && y == 1)
	{
		ft_putchar('C');
	}
	while (x < a)
	{
		ft_putchar('B');
		x++;
	}
	if (x == a && y == 1)
	{
		ft_putchar('A');
	}
}

void	rows(int a, int b, int x, int y)
{
	while (y <= b)
	{
		x = 0;
		while (x <= a)
		{
			if (x == a)
			{
				ft_putchar('B');
				ft_putchar('\n');
			}
			else if (x == 0)
			{
				ft_putchar('B');
			}
			else if (x != 0 && x != a)
			{
				ft_putchar(' ');
			}
			x++;
		}
		y++;
	}
}

void	rush(int a, int b)
{
	if (a < 0 || b < 0)
	{
		write(1, "invalid input", 13);
		return ;
	}
	firstline(a);
	rows(a, b, 1, 1);
	lastline(a);
}
