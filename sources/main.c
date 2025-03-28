/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:19:12 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/29 11:28:25 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_string_array(char **array)
{
	char	**temp;

	temp = array;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	if (array)
		free (array);
}

void	free_stack_exit(t_stack *stack, int error_flag)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	if (error_flag)
		ft_printf("Error\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tokens;
	int		token_count;

	token_count = 0;
	if (argc == 1)
	{
		printf("Error: no arguments.\n");
		return (0);
	}
	stack_a = NULL;
	stack_b = NULL;
	argv++;
	args_verif(argv);
	while (--argc)
	{
		tokens = ft_split(*argv, ' ');
		if (!tokens || !tokens[0])
		{
			free_string_array(tokens);
			exit(1);
		}
		if(!ft_isvalid_integer_str(*tokens))
		{
			free_string_array(tokens);
			exit (0);
		}
		stack_add(&stack_a, tokens);
		free_string_array(tokens);
		// free_stack_exit(stack_a, 0);		// (needs special condition for 3??????)
		argv++;
		token_count++;
	}
	if (token_count == 0)
	{
		free_stack_exit(stack_a, 0);
		return (0);
	}
	if (is_sorted(&stack_a))
	{
		free_stack_exit(stack_a, 0);
		return (0);
	}
	assign_index(stack_a);
	sort_stack(stack_a, stack_b);
	free_stack_exit(stack_a, 0);
	return (0);
}
	
