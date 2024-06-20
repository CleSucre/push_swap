/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:47:05 by julthoma          #+#    #+#             */
/*   Updated: 2024/01/12 17:47:05 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Get the size of the stack.
 *
 * @param t_stack *stack
 * @return int
 */
int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

/**
 * @brief Get the minimum value of the stack.
 *
 * @param t_stack *stack
 * @return int
 */
int	stack_min(t_stack *stack)
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
 * @brief Get the maximum value of the stack.
 *
 * @param t_stack *stack
 * @return int
 */
int	stack_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (-1);
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

/**
 * @brief Get the minimum index of the stack.
 *
 * @param t_stack *stack
 * @return int
 */
int	stack_min_index(t_stack *stack)
{
	int	min;

	if (!stack)
		return (-1);
	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

/**
 * @brief Get the maximum index of the stack.
 *
 * @param t_stack *stack
 * @return int
 */
int	stack_max_index(t_stack *stack)
{
	int	max;

	if (!stack)
		return (-1);
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}
