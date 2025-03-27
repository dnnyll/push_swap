/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:01:23 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/27 13:24:01 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//	if stack_size == 2:
//		swaps one value with the other
//
//	if stack_size == 3:
//		gets the max value (index) of the 3 elements, then rotate the stack accordingly
//		if the largest element is at the top, use ra() to rotate it to the bottom
//		if the largest element is in the second position, use rra() to move it to the top
//		if the stack is not sorted after rotations, you need to swap the first two elements using sa()
//	function to sort 2 elements
//	swaps both elements
void sort_two_elements(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
	// print_stacks(*stack_a, *stack_b);
}

//	function to sort 3 elements with specific patterns
//	hard coded all the possibilities
void	sort_three_elements(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index &&
		(*stack_a)->index < (*stack_a)->next->next->index)
		sa(stack_a);
	else if ((*stack_a)->index > (*stack_a)->next->index &&
			 (*stack_a)->next->index > (*stack_a)->next->next->index)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->index > (*stack_a)->next->next->index &&
			 (*stack_a)->next->index < (*stack_a)->next->next->index)
		ra(stack_a);
	else if ((*stack_a)->index < (*stack_a)->next->index &&
			 (*stack_a)->index > (*stack_a)->next->next->index)
		rra(stack_a);
	else if ((*stack_a)->next->index > (*stack_a)->next->next->index)
	{
		sa(stack_a);
		ra(stack_a);
	}
	// ft_printf("printing at sort_three_elements.\n");
	// print_stacks(*stack_a, NULL);
}

//	function to sort 4 or 5 elements
//	pushes min_index	// Sort the remaining 3 elements
//	sorts the remaining 3 elements
//	pushes back elements from stack B to stack A
void	sort_four_five_elements(t_stack **stack_a, t_stack **stack_b)
{
	while (get_stack_size(*stack_a) > 3)
	{
		while ((*stack_a)->index != get_min_index(*stack_a))
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three_elements(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

// Main sorting function that decides which sub-function to call
int sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size == 2)
		sort_two_elements(stack_a);
	else if (size == 3)
		sort_three_elements(stack_a);
	else if (size == 4 || size == 5)
		sort_four_five_elements(stack_a, stack_b);
	// ft_printf("printing at sort_small.\n");
	// print_stacks(*stack_a, NULL);
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
//		good version but 1 line too long
// int	radix_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	bit_position;
// 	int	max_bits;
// 	int	stack_size;
// 	int	i;
// 	t_stack	*current_node;

// 	max_bits = get_max_bits(*stack_a);
// 	bit_position = 0;
// 	while (bit_position < max_bits)
// 	{
// 		i = 0;
// 		stack_size = get_stack_size(*stack_a);
// 		while (i < stack_size)
// 		{
// 			current_node = *stack_a;
// 			if ((current_node->index & (1 << bit_position)) == 0)
// 				pb(stack_a, stack_b);
// 			else
// 				ra(stack_a);
// 			i++;
// 		}
// 		while (*stack_b)
// 			pa(stack_a, stack_b);
// 		bit_position += 1;
// 	}
// 	return (1);
// }



//				version to debug
// int	radix_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	ft_printf("Calling radix_sort.\n");
// 	print_stacks(*stack_a, *stack_b);
// 	int	bit_position;
// 	int	max_bits;
// 	int	stack_size;
// 	int	i;
// 	t_stack *current_node;

// 	max_bits = get_max_bits(*stack_a);
// 	ft_printf("Max bits = %d\n", max_bits);
// 	bit_position = 0;
// 	while (bit_position < max_bits)
// 	{
// 		ft_printf("Processing bit position = %d\n", bit_position);
// 		i = 0;
// 		stack_size = get_stack_size(*stack_a);
// 		ft_printf("Stack size = %d\n", stack_size);
// 		while (i < stack_size)
// 		{
// 			current_node = *stack_a;
// 			ft_printf("Current node value = %d\n", current_node->value);
// 			if ((current_node->index & (1 << bit_position)) == 0)
// 			{
// 				ft_printf("Pushing value to stack_b. Value = %d\n", current_node->value);
// 				pb(stack_a, stack_b);
// 				print_stack_a(*stack_b);
// 			}
// 			else
// 			{
// 				ft_printf("Rotating stack_a.\n");
// 				ra(stack_a);
// 				print_stack_a(*stack_a);
// 			}
// 			i++;
// 		}
// 		if (*stack_b)
// 		{
// 			ft_printf("Moving elements back to stack_a.\n");
// 			while (*stack_b)
// 			{
// 				pa(stack_a, stack_b);
// 				print_stack_a(*stack_a);
// 			}
// 		}
// 		ft_printf("Finished moving elements back to stack_a.\n");

// 		bit_position += 1;
// 	}
// 	print_stacks(*stack_a, *stack_b);
// 	return (1);
// }

int sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_size;

	stack_size = get_stack_size(stack_a);
	if (stack_size <= 5)
	{
		// ft_printf("Stack size is small (<= 5). Using sort_small.\n");
		sort_small(&stack_a, &stack_b); // This handles sorting for 2-5 elements
	}
	else
	{
		// ft_printf("Stack size is larger. Using radix_sort.\n");
		radix_sort(&stack_a, &stack_b);  // This handles larger stacks efficiently
	}
	// ft_printf("printing at sort_stack.\n");
	// print_stacks(stack_a, NULL);
	return (1);
}



//____________________________________________________________________________________________
// int	sort_small(t_stack *stack_a, t_stack *stack_b)
// {
// 	ft_printf("Calling sort_small.\n");
// 	print_stacks(stack_a, stack_b);
// 	int	stack_size;
// 	int	max_index_value;

// 	stack_size = get_stack_size(stack_a);
// //	swaps one value with the other
// 	if (stack_size == 2)
// 	{
// 		ft_printf("Stack size is 2. Checking if swap is needed...\n");
// 		if (stack_a->value > stack_a->next->value)
// 		{
// 			ft_printf("Swapping the first two elements: ");
// 			sa(&stack_a);
// 			print_stacks(stack_a, stack_b);
// 		}
// 	}
// //	gets the max value of the 3 elements, then rotate the stack accordingly.
// //	if the largest element is at the top, use ra() to rotate it to the bottom.
// //	if the largest element is in the second position, use rra() to move it to the top.
// //	if the stack is not sorted after rotations, you need to swap the first two elements using sa()
// 	else if (stack_size == 3)
// 	{
		
// 		max_index_value = get_max_index_value(stack_a);
// 		if (stack_a->value == max_index_value)
// 		{
// 			ft_printf("case 1.\n");
// 			ra(&stack_a);
// 		}
// 		else if (stack_a->next->value == max_index_value)
// 		{
// 			ft_printf("case 2.\n");
// 			rra(&stack_a);
// 		}
// 		if (stack_a->value > stack_a->next->value)
// 		{
// 			ft_printf("case 3.\n");
// 			sa(&stack_a);
// 		}
// 	}
// 	else if (stack_size == 4 || stack_size == 5)
// 	{
// 		while (get_stack_size(stack_a) > 3)
// 			push_min_index_to_stack_b(&stack_a, &stack_b);
// 		// After pushing the min_index elements to stack_b, we recursively sort the remaining stack_a
// 		sort_small(stack_a, stack_b);
// 		while (stack_b)
// 			pa(&stack_a, &stack_b);
// 		if (stack_a->next && stack_a->value > stack_a->next->value)
// 			sa(&stack_a);
// 		if (stack_a->next->next && stack_a->next->value > stack_a->next->next->value)
// 			ra(&stack_a);
// 	}
// 	print_stacks(stack_a, stack_b);
// 	return (1);
// }

// int	radix_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	ft_printf("Calling radix_sort.\n");
// 	print_stacks(*stack_a, *stack_b);
// 	int	bit_position;
// 	int	max_bits;
// 	int	stack_size;
// 	int	i;
// 	t_stack *current_node;

// 	max_bits = get_max_bits(*stack_a);
// 	bit_position = 0;
// 	while (bit_position < max_bits)
// 	{
// 		i = 0;
// 		stack_size = get_stack_size(*stack_a);
// 		while (i < stack_size)
// 		{
// 			current_node = *stack_a;
// 			if ((current_node->index & (1 << bit_position)) == 0)
// 			{
// 				pb(stack_a, stack_b);
// 				print_stack_a(*stack_b);
// 			}
// 			else
// 			{
// 				ra(stack_a);
// 				print_stack(*stack_a);
// 			}
// 				i++;
// 		}
// 		//	whith 6 input elements i get stuck in this loop
// 		if (*stack_b)
// 		{
// 			ft_printf("Moving elements back to stack_a.\n");
// 			while (*stack_b)
// 			{
// 				pa(stack_a, stack_b);
// 				print_stack_a(*stack_a);
// 			}
// 		}
// 		ft_printf("Finnishing Moving elements back to stack_a.\n");

// 		// while (stack_b != 0)
// 		// {
// 		// 	ft_printf("3\n");
// 		// 	ft_printf("Before pa, stack_b size: %d\n", get_stack_size(*stack_b));
// 		// 	pa(stack_a, stack_b);
// 		// 	ft_printf("After pa, stack_b size: %d\n", get_stack_size(*stack_b));
// 		// }
// 		bit_position += 1;	
// 	}
// 	print_stacks(*stack_a, *stack_b);
// 	return (1);
// }

// int sort_stack(t_stack *stack_a, t_stack *stack_b)
// {
// 	ft_printf("Calling sort_stack.\n");
// 	int stack_size;

// 	stack_size = get_stack_size(stack_a);
// 	ft_printf("stack_size = %d\n.", stack_size);
// 	// Case 1: If the stack size is small (<= 5), use sort_small
// 	if (stack_size <= 5)
// 		sort_small(stack_a, stack_b); // This handles sorting for 2-5 elements
// 	else
// 		// Case 2: If the stack size is larger, use radix_sort
// 		radix_sort(&stack_a, &stack_b);  // This handles larger stacks efficiently
// 	return (1);
// }

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