/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:29:00 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/19 15:47:06 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isvalid_char(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c == '-')
		return (1);
	if (((c == ' ') || (c >= 9 && c <= 13)))
		return (1);
	else
	ft_printf("did i return 0?\n");
		return(0);
}

char	*remove_quotes(char *argv)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	if (argv[0] == '"')
	{
		new_str = malloc(sizeof(char) * (ft_strlen(argv) + 1));
		if (!new_str)
		{
			free (new_str);
			exit (EXIT_FAILURE);
		}
		while (argv[1])
		{
			if (argv[0] != '"')
			{
				new_str[j++] = argv[i];
			}
			i++;
		}
		new_str[j] = '\0';
		return (new_str);
	}
	return (argv);
}

// int	check_duplicates(int *arr, int count)
// {
// 	int	i;

// 	i = 0;

// 	while (arr[i])
// 	{
// 		if ()
// }

