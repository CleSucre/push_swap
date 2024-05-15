/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:38:43 by julthoma          #+#    #+#             */
/*   Updated: 2024/01/11 23:38:43 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Get the minimum value of the stack.
 *
 * @param t_stack* stack
 * @return int
 */
static int	stack_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (-1);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

/**
 * @brief Sort the stack using a small & basic sort algorithm.
 *
 * @param stack_a* stack_a
 * @param stack_b* stack_b
 */
static void	small_sort(t_stack **stack_a, t_stack **stack_b)
{
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

/**
 * @brief Sort the stack using the radix sort algorithm.
 *
 * @param t_stack** stack_a
 * @param t_stack** stack_b
 */
static void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	size;

	i = 0;
	while (i < 32 && !is_sorted(*stack_a))
	{
		size = stack_size(*stack_a);
		while (size-- > 0)
		{
			if ((int)((*stack_a)->value ^ (1L << 31)) & (1 << i))
				ra(stack_a);
			else if (size > 0)
				pb(stack_a, stack_b);
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b);
		i++;
	}
}

/**
 * @brief Choose the best sorting algorithm depending on the stack size.
 *
 * @param t_stack** stack_a
 * @param t_stack** stack_b
 */
void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	if (stack_size(*stack_a) <= 30)
		small_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
