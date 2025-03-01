/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:19:12 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/01 19:24:21 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	main(int argc, char **argv)
{
	int		i = 0;
	char	c = argv [i][0];
	if (argc < 2)
	{
		ft_printf("Error: Invalid input");
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
	{
		while (argv[1][i])
		{
			ft_isvalid_char(c, i);
			ft_printf("%c", argv[1][i++]);
		}
		
		// ft_printf("%s", *argv[1]);
	}
		
		
	return (0);
}
