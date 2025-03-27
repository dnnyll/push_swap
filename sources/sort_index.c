/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:15:53 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/27 11:07:41 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
