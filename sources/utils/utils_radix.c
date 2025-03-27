/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_radix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:46:14 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/27 10:58:11 by daniefe2         ###   ########.fr       */
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
// int get_max_value_index(t_stack *stack)
// {
// 	int max_value_index = stack->index;  // Start with the first element's index
// 	int max_value = stack->value;         // Start with the first element's value

// 	while (stack)
// 	{
// 		if (stack->value > max_value)  // If the current node's value is greater than the max value
// 		{
// 			max_value = stack->value; // Update max value
// 			max_value_index = stack->index;  // Update the index of the max value
// 		}
// 		stack = stack->next;
// 	}
// 	return (max_value_index);
// }

int get_min_index(t_stack *stack)
{
	int	min_index;
	
	min_index = stack->index;
	t_stack *current = stack->next;

	while (current)
	{
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
	}
	return (min_index);
}

// int	get_max_value(t_stack *stack)
// {
// 	int max_value;

// 	max_value = stack->value;
// 	while (stack)
// 	{
// 		if (stack->value > max_value)
// 			max_value = stack->value;
// 		stack = stack->next;
// 	}
// 	return (max_value);
// }

 