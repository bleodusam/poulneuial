/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tin <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:26:21 by tin               #+#    #+#             */
/*   Updated: 2019/07/07 15:26:25 by tin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putint(int i)
{
	char c;

	c = i + '0';
	write(1, &c, 1);
}

void	create_carater(int i)
{
	int a;
	int b;
	int stillfirstzeros;

	stillfirstzeros = 1;
	a = 1000000000;
	while (a > 0)
	{
		b = i / a;
		if (b || !stillfirstzeros || a == 1)
		{
			ft_putint(b);
			stillfirstzeros = 0;
		}
		i = i - a * b;
		a = a / 10;
	}
}

void	ft_putnbr(int n)
{
	char c;

	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		if (n == -2147483648)
		{
			ft_putint(2);
			n = -147483648;
		}
		n = -n;
	}
	create_carater(n);
}
