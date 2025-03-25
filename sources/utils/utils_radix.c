/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_radix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:46:14 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/24 17:37:11 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// finds how many bits are needed to represent the largest number in the stack.
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
	return bits;
}
