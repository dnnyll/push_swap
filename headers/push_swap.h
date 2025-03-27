/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:33:26 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/27 14:11:25 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSHS_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/Libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}t_stack;


//	-=	?????			//////////////////////////////////////////////
int		ft_isvalid_char(char c);
int		ft_isvalid_integer_str(char *str);
int		args_verif(char **argv);
void	free_string_array(char **array);
void	free_stack_exit(t_stack *stack, int error_flag);
void	stack_add(t_stack **stack, char **input_string);
int		duplicate_check(t_stack *stack, int value);
int		is_sorted(t_stack **stack_a);
void	print_stack(t_stack *stack);
void	assign_index(t_stack *stack);
t_stack	*get_last_node(t_stack *stack);
int		get_max_bits(t_stack *stack);
int		get_stack_size(t_stack *stack);
int		get_max_value(t_stack *stack);
void 	print_stack_a(t_stack *stack);
void 	print_stacks(t_stack *stack_a, t_stack *stack_b);
int 	get_max_value_index(t_stack *stack);


//	-=	algorithm				//////////////////////////////////////////////
int		sort_small(t_stack **stack_a, t_stack **stack_b);
int		radix_sort(t_stack **stack_a, t_stack **stack_b);
int 	sort_stack(t_stack *stack_a, t_stack *stack_b);
void sort_two_elements(t_stack **stack_a);
void sort_three_elements(t_stack **stack_a);
void sort_four_five_elements(t_stack **stack_a, t_stack **stack_b);
int get_min_index(t_stack *stack);

//	-=	operations				//////////////////////////////////////////////
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	push_smallest_to_stack_b(t_stack **stack_a, t_stack **stack_b);
int		reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
int		rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

#endif