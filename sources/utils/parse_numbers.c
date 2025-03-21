/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:16:19 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/21 08:04:47 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	
	while (*argv[i])
	{
		if (argv[i][j] == ' ')
		{
			ft_split(argv[i], ' ');
			//store value on linked list node
			// count++;
			i++;
		}
		// else if
		// {
		// 	while (argv[i])
		// 	{
		// 		ft_atoi(argv[i]);
		// 		i++;
		// 	}
		// }
		else
			return (0);
	}
	ft_printf("parse_number ended successfully?!\n");
	return (1);
}
