/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_isfull_stk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:59:39 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/24 17:16:29 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	s_isfull_stk(t_sstack *stack)
{
	return (stack->top == stack->size - 1);
}
