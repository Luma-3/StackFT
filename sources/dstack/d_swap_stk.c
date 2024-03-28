/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_swap_stk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:42:00 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/28 18:39:57 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

void	d_swap_stk(t_dstack *stack)
{
	t_dnode	*tmp;

	tmp = stack->top->next;
	stack->top->next = tmp->next;
	tmp->next = stack->top;
	stack->top = tmp;
}
