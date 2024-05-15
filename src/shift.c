/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 02:17:47 by julthoma          #+#    #+#             */
/*   Updated: 2024/05/08 02:17:47 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 *
 * @param t_stack** stack
*/
void	ra(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*to_free;
	int		tmp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a)->value;
	head = (*stack_a)->next;
	to_free = *stack_a;
	while ((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = stack_new(tmp);
	*stack_a = head;
	free(to_free);
	ft_printf("ra\n");
}
