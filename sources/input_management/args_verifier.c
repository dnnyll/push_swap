/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_verifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:29:47 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/21 10:20:20 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//verifies if the input contains only valid characters
int	args_verif(char **argv)
{
	ft_printf("entering args_verif..\n");
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isvalid_char(argv[i][j]))
			{
				ft_printf("error: invalid char found -> %c\n", argv[i][j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
