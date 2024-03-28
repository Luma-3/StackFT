/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_drop_stk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:15:54 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/28 18:24:46 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

void	d_drop_stk(t_dstack *stack, void (*del)(void *))
{
	t_dnode	*tmp;

	tmp = stack->top;
	if (d_isempty_stk(stack) == 0)
	{
		stack->top = tmp->next;
		del(tmp->data);
		free(tmp);
		stack->size--;
	}
}
