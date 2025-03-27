/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   input_check.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: daniefe2 <daniefe2@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/27 14:03:26 by daniefe2		  #+#	#+#			 */
/*   Updated: 2025/03/27 14:08:41 by daniefe2		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

int input_check(int argc, char **argv)
{
	char **tokens;

	if (argc == 1)
	{
		printf("Error: empty argument.\n");
		return (1);
	}
	argv++;
	while (--argc)
	{
		tokens = ft_split(*argv, ' ');
		if (check_single_number(tokens))
		{
			free_string_array(tokens);
			return (2);
		}
		if (validate_tokens(tokens))
		{
			free_string_array(tokens);
			return (3);
		}
		free_string_array(tokens);
		argv++;
	}
	return (0);
}

int check_single_number(char **tokens)
{
	int token_count = 0;

	while (tokens[token_count] != NULL)
		token_count++;

	if (token_count == 1)
	{
		printf("Single number provided, no sorting needed.\n");
		return (1);
	}
	return (0);
}

int validate_tokens(char **tokens)
{
	if (!ft_isvalid_integer_str(*tokens))
	{
		ft_printf("Error: invalid integer.\n");
		return (1);
	}
	return (0);
}

