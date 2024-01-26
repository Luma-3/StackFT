/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_swap_stk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:49:15 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/26 15:51:47 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

void	s_swap_stk(t_sstack *stk)
{
	int	tmp;

	tmp = stk->data[0];
	stk->data[0] = stk->data[1];
	stk->data[1] = tmp;
}
