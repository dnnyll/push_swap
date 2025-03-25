/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:15:53 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/24 17:50:18 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	ft_printf("Calling print_stack.\n");
	while (stack)
	{
		printf("Value: %d, Index: %d\n", stack->value, stack->index);
		stack = stack->next;
	}
}

//	assigning index to every element of the stack to simplify sorting
void	assign_index(t_stack *stack)
{
	t_stack *min_node;
	t_stack *temp;
	int	i;

	i = 0;
	while (1)  // Keep looping until all nodes have an index
	{
		min_node = NULL;
		temp = stack;
		// Find the smallest unindexed node
		while (temp)
		{
			if (temp->index == -1 && (!min_node || temp->value < min_node->value))
				min_node = temp;
			temp = temp->next;
			}
		// If no more unindexed nodes, break the loop
		if (!min_node)
		break;
		// Assign the next index
		min_node->index = i;
		i++;
	}
	
}
