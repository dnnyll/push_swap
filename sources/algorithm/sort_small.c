/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:35:19 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/31 16:30:47 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	if stack_size == 2:
//		swaps one value with the other
void	sort_two_elements(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

//	if stack_size == 3:
//		gets the max value (index) of the 3 elements
//		then rotate the stack accordingly
//
//		if the largest element is at the top, use ra() to rotate it to the bot
//		if the largest element is in the second position,
//		use rra() to move it to the top
//		if the stack is not sorted after rotations,
//		you need to swaps the first two elements using sa()
void	sort_three_elements(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->index < (*stack_a)->next->next->index)
		sa(stack_a);
	else if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->next->index > (*stack_a)->next->next->index)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->index > (*stack_a)->next->next->index
		&& (*stack_a)->next->index < (*stack_a)->next->next->index)
		ra(stack_a);
	else if ((*stack_a)->index < (*stack_a)->next->index
		&& (*stack_a)->index > (*stack_a)->next->next->index)
		rra(stack_a);
	else if ((*stack_a)->next->index > (*stack_a)->next->next->index)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

//	function to sort 4 or 5 elements
//	pushes min_index	
//	rotates smallest element to the top (stack_a)
//		if min_pos is in the top half, it's cheaper to use ra()
//		if min_pos is in the bottom half, it's cheaper to use rra()
//		when smallest is at top, push to b, repeat until 3 elements
//	sorts the remaining 3 elements
//	pushes back elements from stack B to stack A
void	sort_four_five_elements(t_stack **stack_a, t_stack **stack_b)
{
	int	min_index;
	int	size;
	int	min_pos;

	while (get_stack_size(*stack_a) > 3)
	{
		min_index = get_min_index(*stack_a);
		size = get_stack_size(*stack_a);
		min_pos = get_position_of_index(*stack_a, min_index);
		if (min_pos <= size / 2)
		{
			while ((*stack_a)->index != min_index)
				ra(stack_a);
		}
		else
		{
			while ((*stack_a)->index != min_index)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three_elements(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
