/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:15:53 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/28 14:25:19 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	assigning index to every element of the stack to simplify sorting
//	keeps looping until all nodes have an index
//	finds the smallest unindexed node
//	if there are no more unindexed nodes, breaks the loop
//	assign the next index
void	assign_index(t_stack *stack)
{
	t_stack *min_node;
	t_stack *temp;
	int	i;

	i = 0;
	while (1)
	{
		min_node = NULL;
		temp = stack;
		while (temp)
		{
			if (temp->index == -1 && (!min_node || temp->value < min_node->value))
				min_node = temp;
			temp = temp->next;
		}
		if (!min_node)
		break;
		min_node->index = i;
		i++;
	}
}
