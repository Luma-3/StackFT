/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_init_stk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:06:09 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/30 17:09:22 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

t_dstack	*d_init_stk(void)
{
	t_dstack	*stack;

	stack = (t_dstack *)malloc(sizeof(t_dstack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}
