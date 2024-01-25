/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_init_stk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:44:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/24 18:05:48 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

void	s_init_stk(t_sstack *stack, size_t size)
{
	stack->data = (int *)malloc(sizeof(int) * size);
	if (!stack->data)
		return ;
	stack->top = -1;
	stack->size = size;
}