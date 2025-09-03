/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oal-majd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:11:53 by oal-majd          #+#    #+#             */
/*   Updated: 2025/04/18 18:11:58 by oal-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	first_last(int x)
{
	int	a;

	a = x;
	while (a)
	{
		if (a == x || a == 1)
			ft_putchar('o');
		else
			ft_putchar('-');
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
			ft_putchar('|');
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
	if (x > 0 && y > 0)
	{
		b = y;
		while (b != 0)
		{
			if (b == 1 || b == y)
				first_last(x);
			else
				mid(x);
			ft_putchar('\n');
			b--;
		}
	}
}
