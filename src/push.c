/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 08:07:20 by julthoma          #+#    #+#             */
/*   Updated: 2024/05/04 08:07:20 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 *
 * @param t_stack** stack_a
 * @param t_stack** stack_b
 */
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
}

/**
 * @brief Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 *
 * @param t_stack** stack_a
 * @param t_stack** stack_b
 */
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	pa(stack_b, stack_a);
}

/**
 * @brief rra and rrb at the same time.
 *
 * @param t_stack** stack_a
 * @param t_stack** stack_b
 */
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
