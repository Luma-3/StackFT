/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_len_stk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:32:00 by jbrousse          #+#    #+#             */
/*   Updated: 2024/01/24 17:33:53 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

size_t	s_len_stk(t_sstack *stack)
{
	return (stack->top + 1);
}