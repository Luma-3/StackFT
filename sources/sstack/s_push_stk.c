/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_push_stk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:53:18 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/26 15:56:09 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

void	s_push_stk(t_sstack *stack, int value)
{
	int	i;

	if (s_isfull_stk(stack))
	{
		write(2, "Error : stack is FULL !", 24);
		return ;
	}
	stack->base++;
	i = stack->base;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = value;
}
