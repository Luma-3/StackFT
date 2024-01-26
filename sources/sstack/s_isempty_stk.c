/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_isempty_stk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:55:51 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/26 15:56:09 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

int	s_isempty_stk(t_sstack *stack)
{
	return (stack->base == -1);
}
