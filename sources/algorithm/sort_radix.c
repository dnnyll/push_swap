/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:24:16 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/25 14:27:53 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("Calling sort_small.\n");
	int	stack_size;
	int	max_value;

	stack_size = get_stack_size(stack_a);
//	swaps one value with the other
	if (stack_size == 2)
	{
		if (stack_a->value > stack_a->next->value)
			sa(&stack_a);
	}
//	finds the max value of the 3 elements, then rotate the stack accordingly.
//	if the largest element is at the top, use ra() to rotate it to the bottom.
//	if the largest element is in the second position, use rra() to move it to the top.
//	if the stack is not sorted after rotations, you need to swap the first two elements using sa()
	else if (stack_size == 3)
	{
		max_value = get_max_value(stack_a);
		if (stack_a->value == max_value)
			ra(&stack_a);
		else if (stack_a->next->value == max_value)
			rra(&stack_a);
		if (stack_a->value > stack_a->next->value)
			sa(&stack_a);
	}
	else if (stack_size == 4 || stack_size == 5)
	{
		while (get_stack_size(stack_a) > 3)
			push_smallest_to_stack_b(&stack_a, &stack_b);
		// After pushing the smallest elements to stack_b, we recursively sort the remaining stack_a
		sort_small(stack_a, stack_b);
		while (stack_b)
			pa(&stack_a, &stack_b);
	}
	return (1);
}

int	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("Calling radix_sort.\n");
	int	bit_position;
	int	max_bits;
	int	stack_size;
	int	i;
	t_stack *current_node;

	max_bits = get_max_bits(*stack_a);
	bit_position = 0;
	while (bit_position < max_bits)
	{
		i = 0;
		stack_size = get_stack_size(*stack_a);
		while (i < stack_size)
		{
			current_node = *stack_a;
			if ((current_node->index & (1 << bit_position)) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			i++;
		}
		//	whith 6 input elements i get stuck in this loop
		if (*stack_b) {
			ft_printf("Moving elements back to stack_a.\n");
			while (*stack_b)
				pa(stack_a, stack_b);
		}
		
		// while (stack_b != 0)
		// {
		// 	ft_printf("3\n");
		// 	ft_printf("Before pa, stack_b size: %d\n", get_stack_size(*stack_b));
		// 	pa(stack_a, stack_b);
		// 	ft_printf("After pa, stack_b size: %d\n", get_stack_size(*stack_b));
		// }
		bit_position += 1;	
	}
	return (1);
}

int sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("Calling sort_stack.\n");
	int stack_size;

	stack_size = get_stack_size(stack_a);
	ft_printf("stack_size = %d\n.", stack_size);
	// Case 1: If the stack size is small (<= 5), use sort_small
	if (stack_size <= 5)
		sort_small(stack_a, stack_b); // This handles sorting for 2-5 elements
	else
		// Case 2: If the stack size is larger, use radix_sort
		radix_sort(&stack_a, &stack_b);  // This handles larger stacks efficiently
	return (1);
}

/*

Values:   [ 34, 12, 89, 3, 77 ]
Indices:  [  3,  1,  4, 0, 2  ]
Binary:   [ 011, 001, 100, 000, 010 ]

Check the rightmost bit (0th bit):
Indices:  [ 011, 001, 100, 000, 010 ]
Bit 0:    [  1,   1,   0,   0,   0  ]
Move 0s → stack_b → [ 4, 0, 2 ] (pb)
Keep 1s → stack_a → [ 3, 1 ] (ra)
Restore `stack_b` → stack_a = [ 3, 1, 4, 0, 2 ]

Check 2nd rightmost bit (1st bit):
Indices:  [ 011, 001, 100, 000, 010 ]
Bit 1:    [  1,   0,   0,   0,   1  ]
Move 0s → stack_b → [ 1, 4, 0 ] (pb)
Keep 1s → stack_a → [ 3, 2 ] (ra)
Restore `stack_b` → stack_a = [ 3, 2, 1, 4, 0 ]

Check 3rd bit (2nd bit):
Indices:  [ 011, 001, 100, 000, 010 ]
Bit 2:    [  0,   0,   1,   0,   0  ]
Move 0s → stack_b → [ 3, 1, 0, 2 ] (pb)
Keep 1s → stack_a → [ 4 ] (ra)
Restore `stack_b` → stack_a = [ 4, 3, 1, 0, 2 ]

*/