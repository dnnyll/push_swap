/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_radix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:46:14 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/31 16:23:36 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	finds the largest index in the stack.
//	finds how many bits are needed to represent the largest number in the stack.
int	get_max_bits(t_stack *stack)
{
	int	max_index;
	int	bits;

	max_index = 0;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

//	counts how many elements are in stack_a.
//	helps control how many times we process elements in each bitwise pass.
int	get_stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	get_min_index(t_stack *stack)
{
	int		min_index;
	t_stack	*current;

	min_index = stack->index;
	current = stack->next;
	while (current)
	{
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
	}
	return (min_index);
}

//	 return -1 should never happen if index exists
int	get_position_of_index(t_stack *stack, int target_index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target_index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}
