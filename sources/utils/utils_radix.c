/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_radix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:46:14 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/25 16:29:31 by daniefe2         ###   ########.fr       */
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
// returns the higher value in the stack
int	get_max_value(t_stack *stack)
{
	int max_value;

	max_value = stack->value;
	while (stack)
	{
		if (stack->value > max_value)
			max_value = stack->value;
		stack = stack->next;
	}
	return (max_value);
}

 