/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:38:43 by julthoma          #+#    #+#             */
/*   Updated: 2024/01/11 23:38:43 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sort the stack equal to or smaller than 3.
 *
 * @param t_stack **stack_a
 */
void	tiny_sort(t_stack **stack_a)
{
	int		max;

	if (is_sorted(*stack_a))
		return ;
	max = stack_max(*stack_a);
	if ((*stack_a)->value == max)
		ra(stack_a);
	else if ((*stack_a)->next->value == max)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

/**
 * @brief Sort the stack equal to or smaller than 5.
 *
 * @param t_stack **stack_a
 * @param t_stack **stack_b
 */
void	small_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;

	min = stack_min(*stack_a);
	max = stack_max(*stack_a);
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->value == min || (*stack_a)->value == max)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	tiny_sort(stack_a);
	while (*stack_b && (*stack_b)->next != NULL)
	{
		if ((*stack_b)->value == max)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			pa(stack_a, stack_b);
		}
		else
			rb(stack_b);
	}
	pa(stack_a, stack_b);
}

/**
 * @brief Sort the stack using a small & basic sort algorithm.
 *
 * @param t_stack **stack_a
 * @param t_stack **stack_b
 */
void	medium_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	while (*stack_a)
	{
		if ((*stack_a)->value == stack_min(*stack_a))
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
