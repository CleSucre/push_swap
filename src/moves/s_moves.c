/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 08:07:20 by julthoma          #+#    #+#             */
/*   Updated: 2024/05/04 08:07:20 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 *
 * @param t_stack **stack_a
 */
void	sa(t_stack **stack_a)
{
	int	tmp;
	int	tmp2;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a)->value;
	tmp2 = (*stack_a)->index;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->index = (*stack_a)->next->index;
	(*stack_a)->next->value = tmp;
	(*stack_a)->next->index = tmp2;
	ft_printf("sa\n");
}
