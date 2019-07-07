/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tin <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:26:39 by tin               #+#    #+#             */
/*   Updated: 2019/07/07 15:26:42 by tin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check_begining(char *str)
{
	int i;
	int output;

	i = 0;
	output = 1;
	while (str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if(str[i]  == '-')
			output = -1 * output;
		i++;
	}
	return (output);
}

int check_empty_length(char *str)
{
	int i;

	i = 0;
	while (!(str[i] >= '0' && str[i] <= '9') &&
	 (str[i] == '-' || str[i] == '+' || str[i] == ' '))
			i++;

	return (i);
}

int check_full_length(char *str)
{
	int i;

	i = check_empty_length(str);
	while(str[i] >= '0' && str[i] <= '9')
	{
		i++;
	}
	return (i);
}

int ft_atoi(char *str)
{
	int i;
	long output;
	int disaine;

	output = 0;
	i = check_full_length(str);
	if (i == check_empty_length(str))
		return (0);
	disaine = 1;
	while(i > check_empty_length(str))
	{
		output = output + (long)((str[i - 1] - '0') * disaine);


		printf("str[i] : %d\n", (str[i - 1] - '0') );

			printf("output : %ld\n", output );
		disaine = disaine * 10;
		i--;
	}
	return(((int)output) * check_begining(str));
}
