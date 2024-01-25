/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_swap_stk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:49:15 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/25 15:52:59 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

void	s_swap_stk(t_sstack *stk)
{
	int	tmp;

	tmp = s_getat_stk(stk, stk->top);
	s_update_at_stk(stk, stk->top, s_getat_stk(stk, stk->top - 1));
	s_update_at_stk(stk, stk->top - 1, tmp);
}
