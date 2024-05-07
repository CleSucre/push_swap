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
	int	value;

	if (!*stack_b)
		return ;
	value = pop(stack_b);
	push(stack_a, value);
	ft_printf("pa\n");
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
	int	value;

	if (!*stack_a)
		return ;
	value = pop(stack_a);
	push(stack_b, value);
	ft_printf("pb\n");
}
