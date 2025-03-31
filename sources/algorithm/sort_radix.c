/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:01:23 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/31 14:36:35 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Main sorting function that decides which sub-function to call
int	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size == 2)
		sort_two_elements(stack_a);
	else if (size == 3)
		sort_three_elements(stack_a);
	else if (size == 4 || size == 5)
		sort_four_five_elements(stack_a, stack_b);
	return (1);
}

int	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	bit_position;
	int	max_bits;
	int	stack_size;
	int	i;

	max_bits = get_max_bits(*stack_a);
	bit_position = 0;
	while (bit_position < max_bits)
	{
		stack_size = get_stack_size(*stack_a);
		i = 0;
		while (i++ < stack_size)
		{
			if (((*stack_a)->index & (1 << bit_position)) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		bit_position++;
	}
	return (1);
}

int	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	if (stack_size <= 5)
		sort_small(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	return (1);
}

/*
Values:   [ 34, 12, 89, 3, 77 ]
Indices:  [  3,  1,  4, 0, 2  ]
Binary:   [ 011, 001, 100, 000, 010 ]

Check the rightmost bit (0th bit):
Indices:  [ 011, 001, 100, 000, 010 ]
Bit 0:	[  1,   1,   0,   0,   0  ]
Move 0s → stack_b → [ 4, 0, 2 ] (pb)
Keep 1s → stack_a → [ 3, 1 ] (ra)
Restore `stack_b` → stack_a = [ 3, 1, 4, 0, 2 ]

Check 2nd rightmost bit (1st bit):
Indices:  [ 011, 001, 100, 000, 010 ]
Bit 1:	[  1,   0,   0,   0,   1  ]
Move 0s → stack_b → [ 1, 4, 0 ] (pb)
Keep 1s → stack_a → [ 3, 2 ] (ra)
Restore `stack_b` → stack_a = [ 3, 2, 1, 4, 0 ]

Check 3rd bit (2nd bit):
Indices:  [ 011, 001, 100, 000, 010 ]
Bit 2:	[  0,   0,   1,   0,   0  ]
Move 0s → stack_b → [ 3, 1, 0, 2 ] (pb)
Keep 1s → stack_a → [ 4 ] (ra)
Restore `stack_b` → stack_a = [ 4, 3, 1, 0, 2 ]
*/