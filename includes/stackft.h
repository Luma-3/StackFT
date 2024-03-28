/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:35:58 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/28 18:55:12 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKFT_H
# define STACKFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_sstack
{
	int	*data;
	int	base;
	int	size;
}		t_sstack;

typedef struct s_dnode
{
	void			*data;
	struct s_dnode	*next;
}		t_dnode;

typedef struct s_dstack
{
	t_dnode	*top;
	size_t	size;
}		t_dstack;

//////////////////////////////
//////// STATIC STACK ////////
//////////////////////////////

void		s_clear_stk(t_sstack *stack);
void		s_init_stk(t_sstack *stack, size_t size);
int			s_isempty_stk(t_sstack *stack);
int			s_isfull_stk(t_sstack *stack);
size_t		s_len_stk(t_sstack *stack);
int			s_pop_stk(t_sstack *stack);
void		s_push_stk(t_sstack *stack, int value);
void		s_rolldown_stk(t_sstack *stk);
void		s_rollup_stk(t_sstack *stk);
void		s_swap_stk(t_sstack *stk);

//////////////////////////////
//////// DYNAMIC STACK ///////
//////////////////////////////

void		d_clear_stk(t_dstack *stack, void (*del)(void *));
void		d_drop_stk(t_dstack *stack, void (*del)(void *));
t_dstack	*d_init_stk(void);
int			d_isempty_stk(t_dstack *stack);
void		*d_pop_stk(t_dstack *stack);
int			d_push_stk(t_dstack *stack, void *data);
void		d_swap_stk(t_dstack *stack);

#endif //STACKFT_H