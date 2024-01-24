/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_getat_stk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:25:40 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/24 17:30:58 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	s_getat_stk(t_sstack *stack, int index)
{
	if (stack->top >= index)
		return (stack->data[index]);
	write(2, "Error : Index is to heigt", 26);
	return (-1);
}
