/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_verifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:29:47 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/19 15:49:41 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_verif(int argc, char ** argv)
{
	// int	i;

	// i = 0;
	if (argc < 2)
	{
		ft_printf("Error: Invalid input.\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
	{
		int	i;

		i = 0;
		remove_quotes(argv[1]);
		ft_printf("argv: %s\n", argv[1]);
		ft_printf("argv[1][0]: %c\n", argv[1][0]);
		if (ft_isvalid_char(argv[1][i]) == 1)
		{
			ft_printf("im here\n");
			ft_printf("%c\n", argv[1][i++]);
			//incrementing i in these statements doesnt seem logical
		}
		ft_printf("argv[1][1]: %c\n", argv[1][1]);
		ft_printf("i = %d\n", i);
		if (ft_isvalid_char(argv[1][i]) == 0)
		{
			ft_printf("%c\n", argv[1][i++]);
			ft_printf("error: an invalid char has been found\n");
			return (0);
		}
		while (argv[1][i])
		{
			if (argv[1][i] == ' ')
				ft_printf("there's s pace.\n");
				// parse_number(**argv, count?);
			else
				i++;
			break ;
		}
	}
	// ft_printf("%s", *argv[1]);
	return (0);
}
