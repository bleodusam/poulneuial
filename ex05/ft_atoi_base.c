/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tin <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 21:17:47 by tin               #+#    #+#             */
/*   Updated: 2019/07/08 16:24:47 by tin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		sign(char *str)
{
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' ||
		str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1 * sign;
		i++;
	}
	return (sign);
}

int		check_begining(char *str)
{
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' ||
		str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
		i++;
	return (i);
}

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

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		j;
	long	output;

	i = check_begining(str);
	output = 0;
	if (base_settings(base) == 1 || base_settings(base) == 0)
		return (0);
	j = -1;
	while (j < base_settings(base))
	{
		j++;
		if (str[i] == base[j])
		{
			output = output * (base_settings(base)) + j;
			i++;
			j = -1;
		}
	}
	return ((int)output * sign(str));
}
