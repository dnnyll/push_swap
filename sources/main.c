/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:19:12 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/22 12:30:16 by daniefe2         ###   ########.fr       */
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
		free(array);
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
	// t_stack	*stack_b;
	char **tokens;
	int i = 0;
	if (argc == 1)
		return (0);
	stack_a = NULL;
	// stack_b = NULL;
	argv++;
	while (--argc)
	{
		args_verif(argv);
		tokens = ft_split(*argv, ' ');
		ft_printf("tokens[%d]: %s\n", i, tokens[i]); 
		stack_add(&stack_a, tokens);
		free_string_array(tokens);
		argv++;
	}
	//sorting
	free_stack_exit(stack_a, 0);
	printf("end\n");
	return (0);
}
	
