/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:39:44 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/24 17:35:08 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//	checks if stack_a is sorted
//	checks if stack_a hsd only one rlement (current_node->next == NULL)
//	it allows exactly one out-of-order pair, but only if it doesn’t form a rotation.

int	is_sorted(t_stack **stack_a)
{
	t_stack	*current_node;
	int		unsorted_count;

	current_node = *stack_a;
	unsorted_count = 0;
	while (current_node->next)
	{
		if (current_node->value > current_node->next->value)
			unsorted_count++;
		if (unsorted_count > 1)
			return (0);
		current_node = current_node->next;
	}
	if (unsorted_count == 1 && current_node->value > (*stack_a)->value)
		return (0);
	return (1);
}
