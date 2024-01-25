/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_getat_stk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:25:40 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/24 18:05:46 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

int	s_getat_stk(t_sstack *stack, int index)
{
	if (stack->top >= index)
		return (stack->data[index]);
	write(2, "Error : Index is to heigt", 26);
	return (-1);
}
