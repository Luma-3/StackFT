/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:35:58 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/25 16:56:56 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKFT_H
# define STACKFT_H

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
void	s_rolldown_stk(t_sstack *stk);
void	s_rollup_stk(t_sstack *stk);
void	s_swap_stk(t_sstack *stk);
void	s_update_at_stk(t_sstack *stack, int index, int value);

#endif //STACKFT_H