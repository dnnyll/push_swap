/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:29:00 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/21 14:01:10 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isvalid_char(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c == '-')
		return (1);
	if (((c == ' ') || (c >= 9 && c <= 13)))
		return (1);
	else
	ft_printf("did i return 0?\n");
		return(0);
}
t_stack	*get_last_node(t_stack *stack)
{
	t_stack	*last_node;

	last_node = stack;
	while (last_node && last_node->next)
		last_node = last_node->next;
	return (last_node);
}

int	duplicate_check(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
		{
			ft_printf("got here\n");
			exit(EXIT_FAILURE);
			return (1);	
		}
			stack = stack ->next;
	}
	return (0);
}
void	stack_add(t_stack **stack, char **input_string)
{
	t_stack	*last_node;
	t_stack	*new_node;

	last_node = get_last_node(*stack);
	int i = 0;
	
	while (*input_string)
	{
		new_node = malloc(sizeof(*new_node));
		if (!new_node)
			free_stack_exit(*stack, 1);
		ft_printf("input_string[%d]: %s\n", i, input_string[i]); 
		new_node->value = ft_atoi(*input_string);
		ft_printf("new_node->value = %d\n", new_node->value); 
		new_node->next = NULL;
		if (duplicate_check(*stack, new_node->value))
			free_stack_exit(*stack, 1);
		if (!stack)
			*stack = new_node;
		if (last_node)
			last_node->next = new_node;
		last_node = new_node;
		input_string++;
	}
}
