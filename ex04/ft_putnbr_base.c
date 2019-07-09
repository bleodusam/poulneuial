/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tin <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:26:53 by tin               #+#    #+#             */
/*   Updated: 2019/07/09 10:01:50 by tin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long	base_settings(char *base)
{
	long	i;
	long	j;
	int		output;

	i = 0;
	output = 0;
	while (base[i] != '\0')
	{
		if ((base[i] >= 'A' && base[i] <= 'Z') ||
			(base[i] >= 'a' && base[i] <= 'z') ||
				(base[i] >= '0' && base[i] <= '9'))
		{
			j = -1;
			while (++j < i)
			{
				if (base[i] == base[j])
					return (0);
			}
			output++;
		}
		i++;
	}
	if (output == 1 || output == 0 || output != i)
		return (0);
	return (output);
}

long	max_multipl_base(char *base)
{
	long max_int;
	long max_multipl;
	long born_base;

	max_int = 2147483648;
	born_base = base_settings(base);
	max_multipl = born_base;
	while (max_int)
	{
		max_int = max_int / born_base;
		max_multipl = max_multipl * born_base;
	}
	return (max_multipl);
}

void	print_number(long nb, char *base, long max_multipl)
{
	char	c;
	long	born_base;
	int		firstzeros;

	firstzeros = 1;
	born_base = base_settings(base);
	while (max_multipl)
	{
		c = base[nb / max_multipl];
		nb = nb - (nb / max_multipl) * max_multipl;
		max_multipl = max_multipl / born_base;
		if (firstzeros && (nb / max_multipl))
		{
			firstzeros = 0;
			continue;
		}
		if (!firstzeros)
			write(1, &c, 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long l_nbr;
	char c;

	l_nbr = (long)nbr;
	if (base_settings(base))
	{
		c = '-';
		if (l_nbr < 0)
		{
			write(1, &c, 1);
			l_nbr = -1 * l_nbr;
		}
		print_number(l_nbr, base, max_multipl_base(base));
	}
}
