/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:13:03 by kadas             #+#    #+#             */
/*   Updated: 2025/04/18 20:18:27 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	first(int x)
{
	int	a;

	a = x;
	while (a)
	{
		if (a == x)
			ft_putchar('A');
		else if (a == 1)
			ft_putchar('C');
		else
			ft_putchar('B');
		a--;
	}
}

void	last(int x)
{
	int	a;

	a = x;
	while (a)
	{
		if (a == x)
			ft_putchar('A');
		else if (a == 1)
			ft_putchar('C');
		else
			ft_putchar('B');
		a--;
	}
}

void	mid(int x)
{
	int	a;

	a = x;
	while (a)
	{
		if (a == x || a == 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
		a--;
	}
}

void	rush(int x, int y)
{
	int	b;

	if (x < 0 || y < 0)
	{
		write(1, "invalid input", 13);
		return ;
	}
	b = y;
	while (b != 0)
	{
		if (b == y)
			first(x);
		else if (b == 1)
			last(x);
		else
			mid(x);
		ft_putchar('\n');
		b--;
	}
}
