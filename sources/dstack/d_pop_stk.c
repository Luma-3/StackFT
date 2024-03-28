/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_pop_stk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:34:37 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/28 18:39:28 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

void	*d_pop_stck(t_dstack *stack)
{
	void	*data;
	t_dnode	*tmp;

	data = stack->top->data;
	tmp = stack->top->next;
	free(stack->top);
	stack->top = tmp;
	stack->size--;
	return (data);
}
