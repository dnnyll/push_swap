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

static int	process_token(char **tokens, t_stack **stack_a)
{
	int	i;

	i = 0;
	if (!tokens || !tokens[0])
	{
		free_string_array(tokens);
		return (0);
	}
	while (tokens[i])
	{
		if (tokens[i][0] == '-' && tokens[i][1] == '\0')
		{
			free_string_array(tokens);
			return (0);
		}
		if (!ft_isvalid_integer_str(tokens[i]))
		{
			free_string_array(tokens);
			return (0);
		}
		i++;
	}
	stack_add(stack_a, tokens);
	free_string_array(tokens);
	return (1);
}

t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**tokens;
	int		token_count;

	token_count = 0;
	stack_a = NULL;
	argv++;
	args_verif(argv);
	while (--argc)
	{
		if (**argv == '\0')
			free_stack_exit(0, 1);
		tokens = ft_split(*argv, ' ');
		if (!process_token(tokens, &stack_a))
			free_stack_exit(stack_a, 1);
		argv++;
		token_count++;
	}
	if (token_count == 0)
		return (NULL);
	return (stack_a);
}

int	is_input_valid(t_stack *stack_a)
{
	if (!stack_a)
		return (0);
	if (is_sorted(&stack_a))
		return (0);
	return (1);
}
