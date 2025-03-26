/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:39:44 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/26 10:51:33 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//	checks if stack_a is sorted
//	checks if stack_a hsd only one element (current_node->next == NULL)

int	is_sorted(t_stack **stack_a)
{
	t_stack	*current_node;

	current_node = *stack_a;
	while (current_node->next)
	{
		if (current_node->value > current_node->next->value)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}
