/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:19:12 by daniefe2          #+#    #+#             */
/*   Updated: 2025/04/16 10:15:35 by daniefe2         ###   ########.fr       */
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
		ft_putendl_fd(("Error"), 2);
	exit(0);
}

//	assigning index to every element of the stack to simplify sorting
//	keeps looping until all nodes have an index
//	finds the smallest unindexed node
//	if there are no more unindexed nodes, breaks the loop
//	assign the next index
void	assign_index(t_stack *stack)
{
	t_stack	*min_node;
	t_stack	*temp;
	int		i;

	i = 0;
	while (1)
	{
		min_node = NULL;
		temp = stack;
		while (temp)
		{
			if (temp->index == -1
				&& (!min_node || temp->value < min_node->value))
				min_node = temp;
			temp = temp->next;
		}
		if (!min_node)
			break ;
		min_node->index = i;
		i++;
	}
}
// The program must only output a list of instructions to sort the numbers
// if input is valid and not already sorted.
// The subject defines error cases as:
//	Invalid input (non-integer, overflow)
//	Duplicates
//	Invalid format (e.g., spaces in weird places)

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_b = NULL;
	stack_a = parse_arguments(argc, argv);
	if (!is_input_valid(stack_a))
	{
		free_stack_exit(stack_a, 0);
		return (0);
	}
	assign_index(stack_a);
	sort_stack(&stack_a, &stack_b);
	free_stack_exit(stack_a, 0);
	return (0);
}
