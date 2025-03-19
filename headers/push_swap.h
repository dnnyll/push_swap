/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:33:26 by daniefe2          #+#    #+#             */
/*   Updated: 2025/03/19 15:46:56 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSHS_SWAP_H

# include <string.h>
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/Libft/libft.h"


//	-=	?????			//////////////////////////////////////////////
int		ft_isvalid_char(char c);
int		args_verif(int argc, char **argv);
int		parse_numbers(char **argv);
char	*remove_quotes(char *argv);

#endif