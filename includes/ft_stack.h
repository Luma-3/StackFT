/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:35:58 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/24 17:45:04 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_sstack
{
	int	*data;
	int	top;
	int	size;
}		t_sstack;

void	s_clear_stk(t_sstack *stack);
int		s_getat_stk(t_sstack *stack, int index);
void	s_init_stk(t_sstack *stack, size_t size);
int		s_isempty_stk(t_sstack *stack);
int		s_isfull_stk(t_sstack *stack);
size_t	s_len_stk(t_sstack *stack);
int		s_pop_stk(t_sstack *stack);
void	s_push_stk(t_sstack *stack, int value);
void	s_update_at_stk(t_sstack *stack, int index, int value);

#endif //FT_STACK_H