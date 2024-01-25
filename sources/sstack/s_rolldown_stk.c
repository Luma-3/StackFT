/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rolldown_stk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:51:13 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/25 16:56:14 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

void	s_rolldown_stk(t_sstack *stk)
{
	int	i;
	int	tmp;

	if (s_isempty_stk(stk))
		return ;
	tmp = stk->data[0];
	i = 0;
	while (i < stk->top)
	{
		stk->data[i] = stk->data[i + 1];
		i++;
	}
	stk->data[stk->top] = tmp;
}
