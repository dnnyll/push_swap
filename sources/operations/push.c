/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:23:56 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/27 11:27:54 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*moved_node;

	if (!*stack_b)
		return ;
	moved_node = *stack_b;
	*stack_b = (*stack_b)->next;
	moved_node->next = *stack_a;
	*stack_a = moved_node;
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*moved_node;

	if (!*stack_a)
		return ;
	moved_node = *stack_a;
	*stack_a = (*stack_a)->next;
	moved_node->next = *stack_b;
	*stack_b = moved_node;
	ft_printf("pb\n");
}
