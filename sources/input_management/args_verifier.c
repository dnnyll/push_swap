/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_verifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:29:47 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/27 11:28:24 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//verifies if character is valid
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
//	checks if INT_MIN or INT_MAX have been reached
//	makes sure that the - sign is placed at the beginning of a number
int	ft_isvalid_integer_str(char *str)
{
	int	index;
	int	length;

	index = 0;
	if (str[0] == '-')
		index++;
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (0);
		index++;
	}
	length = ft_strlen(str);
	if ((str[0] != '-' && length > 10) || (str[0] == '-' && length > 11))
		return (0);
	if (length == 10 && str[0] != '-' && ft_strncmp(str, "2147483647", 10) > 0)
		return (0);
	if (length == 11 && str[0] == '-' && \
			ft_strncmp(str + 1, "2147483648", 10) > 0)
		return (0);
	return (1);
}
//	iterates through my input string and verifies if all characters are valid
int	args_verif(char **argv)
{
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
