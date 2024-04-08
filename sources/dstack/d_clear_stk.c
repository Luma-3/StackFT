/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_clear_stk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:59:26 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/04 16:58:55 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

void	d_clear_stk(t_dstack *stack, void (*del)(void *))
{
	t_dnode	*tmp1;
	t_dnode	*tmp2;

	tmp1 = stack->top;
	tmp2 = stack->top->next;
	while (tmp1->data != NULL)
	{
		del(tmp1->data);
		free(tmp1);
		tmp1 = tmp2;
		tmp2 = tmp2->next;
	}
	stack->size = 0;
	stack->top = NULL;
}
