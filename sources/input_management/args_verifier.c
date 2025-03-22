/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_verifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:29:47 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/22 11:56:38 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//verifies if the input contains only valid characters
int	ft_isvalid_char(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c == '-')
		return (1);
	if (((c == ' ') || (c >= 9 && c <= 13)))
		return (1);
	else
		return(0);
}
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
				exit(EXIT_FAILURE);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
