/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:37:00 by julthoma          #+#    #+#             */
/*   Updated: 2024/06/19 23:37:00 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Clear the stack.
 *
 * @param t_stack **stack
 */
void	*stack_clear(t_stack **stack)
{
	t_stack	*t;

	while (*stack)
	{
		t = (*stack)->next;
		free(*stack);
		(*stack) = t;
	}
	return (NULL);
}

/**
 * @brief Create a new stack element.
 *
 * @param int value
 * @return t_stack *
 */
t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

/**
 * @brief Get the last element of the stack.
 *
 * @param t_stack *stack
 * @return t_stack *
 */
t_stack	*stack_last(t_stack *stack)
{
	t_stack	*t;

	if (!stack)
		return (NULL);
	t = stack;
	while (t->next)
		t = t->next;
	return (t);
}

/**
 * @brief Add a new element at the beginning of the stack.
 *
 * @param t_stack **stack
 * @param t_stack *new
 */
void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*t;

	if (!stack || !new)
		return ;
	if (*stack)
	{
		t = stack_last(*stack);
		t->next = new;
	}
	else
		(*stack) = new;
}

/**
 * @brief Check if the stack is sorted.
 *
 * @param stack *stack
 * @return int 1 if the stack is sorted, 0 otherwise
 */
int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
