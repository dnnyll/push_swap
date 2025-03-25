/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:29:00 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/24 17:30:48 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicate_check(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);	
		stack = stack->next;
	}
	return (0);
}

t_stack	*get_last_node(t_stack *stack)
{
	t_stack	*last_node;

	last_node = stack;
	while (last_node && last_node->next)
		last_node = last_node->next;
	return (last_node);
}

void	stack_add(t_stack **stack, char **input_string)
{
	t_stack	*new_node;
	t_stack	*last_node;
	int		value;
	int		i;

	i = 0;
	while (input_string[i])
	{
		value = ft_atoi(input_string[i]);
		if (duplicate_check(*stack, value) == 1)
		{
			ft_printf("Error: duplicate.\n");
			free_stack_exit(*stack, 1);
			exit(0);
		}
		new_node = malloc(sizeof(*new_node));
		if (!new_node)
			free_stack_exit(*stack, 1);
		new_node->value = value;
		new_node->index = -1;
		new_node->next = NULL;
		ft_printf("input_string[%d]: %s\n", i, input_string[i]);
		ft_printf("new_node->value = %d\n", new_node->value);
		if (!*stack)
			*stack = new_node;
		else
		{
			last_node = get_last_node(*stack);
			last_node->next = new_node;
		}
		i++;
	}
}
