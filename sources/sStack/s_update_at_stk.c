/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_update_at_stk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:40:08 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/24 18:06:01 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

void	s_update_at_stk(t_sstack *stack, int index, int value)
{
	if (stack->top >= index)
		stack->data[index] = value;
	else
		write(2, "Error : Index is to heigt", 26);
}
