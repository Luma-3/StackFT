/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_push_stk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:53:18 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/24 17:16:33 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	s_push_stk(t_sstack *stack, int value)
{
	if (!s_isfull_stk(stack))
		stack->data[++stack->top] = value;
	else
		write(2, "Error : stack is FULL !", 24);
}
