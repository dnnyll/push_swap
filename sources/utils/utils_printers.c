/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:06:11 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/26 13:34:06 by daniefe2         ###   ########.fr       */
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
void print_stack_a(t_stack *stack)
{
	t_stack *temp = stack;

	ft_printf("\nStack:\n");
	while (temp)
	{
		ft_printf("%d\n", temp->value);
		temp = temp->next;
	}
	ft_printf("---------------\n");
}
void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *temp_a = stack_a;
	t_stack *temp_b = stack_b;

	ft_printf("\nStack A:\n");
	while (temp_a)
	{
		ft_printf("Value: %d, Index: %d\n", temp_a->value, temp_a->index);
		temp_a = temp_a->next;
	}

	ft_printf("\nStack B:\n");
	while (temp_b)
	{
		ft_printf("Value: %d, Index: %d\n", temp_b->value, temp_b->index);
		temp_b = temp_b->next;
	}
	ft_printf("--------------------\n");
}