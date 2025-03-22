/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:33:26 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/22 12:31:05 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSHS_SWAP_H

# include <string.h>
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/Libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}t_stack;


//	-=	?????			//////////////////////////////////////////////
int		ft_isvalid_char(char c);
int		args_verif(char **argv);
int		parse_number(char **argv);
void	free_string_array(char **array);
void	free_stack_exit(t_stack *stack, int error_flag);
void	stack_add(t_stack **stack, char **input_string);
int		duplicate_check(t_stack *stack, int value);



#endif