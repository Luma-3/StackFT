/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_clear_stk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:59:26 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/28 19:01:35 by jbrousse         ###   ########.fr       */
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
	}
	stack->size = 0;
	stack->top = NULL;
}
