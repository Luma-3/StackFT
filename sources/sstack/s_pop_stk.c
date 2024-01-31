/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_pop_stk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:08:14 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/31 13:13:52 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

int	s_pop_stk(t_sstack *stack)
{
	int	i;
	int	popped_value;

	if (s_isempty_stk(stack))
		return (-1);
	i = 0;
	popped_value = stack->data[0];
	while (i < stack->base)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->base--;
	return (popped_value);
}
