/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:29:00 by daniefe2          #+#    #+#             */
/*   Updated: 2025/04/11 15:03:26 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicate_check(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_stack	*get_last_node(t_stack *stack)
{
	t_stack	*last_node;

	last_node = stack;
	while (last_node && last_node->next)
		last_node = last_node->next;
	return (last_node);
}
//	checks if stack_a is sorted
//	checks if stack_a hsd only one element (current_node->next == NULL)

int	is_sorted(t_stack **stack_a)
{
	t_stack	*current_node;

	if (!stack_a || !*stack_a)
		return (1);
	current_node = *stack_a;
	while (current_node->next)
	{
		if (current_node->value > current_node->next->value)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}
