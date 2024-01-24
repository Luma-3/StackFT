/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_pop_stk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:08:14 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/24 17:22:56 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	s_pop_stk(t_sstack *stack)
{
	if (!s_isempty_stk(stack))
		return (stack->data[stack->top--]);
	else
	{
		write(2, "Error : stack is EMPTY !", 25);
		return (-1);
	}
}
