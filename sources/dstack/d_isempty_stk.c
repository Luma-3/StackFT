/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_isempty_stk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:13:30 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/28 18:15:30 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

int	d_isempty(t_dstack *stack)
{
	if (stack->size == 0)
		return (1);
	return (0);
}
