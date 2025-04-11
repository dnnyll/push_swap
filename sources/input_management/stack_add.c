/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:46:29 by daniefe2          #+#    #+#             */
/*   Updated: 2025/04/11 15:40:51 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Creates a new stack node with the given value
//	Returns the new node or NULL on allocation failure
t_stack	*create_stack_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

//	Adds a single value to the stack
//	Returns 1 on success, 0 on failure
int	add_value_to_stack(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (duplicate_check(*stack, value) == 1)
	{
		ft_putendl_fd(("Error"), 2);
		return (0);
	}
	new_node = create_stack_node(value);
	if (!new_node)
		return (0);
	if (!*stack)
		*stack = new_node;
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = new_node;
	}
	return (1);
}

//Adds values from input strings to the stack
//Returns 1 on success, 0 on failure
int	stack_add(t_stack **stack, char **input_string)
{
	int	i;
	int	value;

	i = 0;
	while (input_string[i])
	{
		value = ft_atoi(input_string[i]);
		if (!add_value_to_stack(stack, value))
		{
			free_string_array(input_string);
			free_stack_exit(*stack, 0);
			return (0);
		}
		i++;
	}
	return (1);
}
