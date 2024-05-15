/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:47:05 by julthoma          #+#    #+#             */
/*   Updated: 2024/01/12 17:47:05 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Clear the stack.
 *
 * @param t_stack** stack
 */
void	stack_clear(t_stack **stack)
{
	t_stack	*t;

	while (*stack)
	{
		t = (*stack)->next;
		free(*stack);
		(*stack) = t;
	}
}

/**
 * @brief Create a new stack element.
 *
 * @param int value
 * @param unsigned int index
 * @param int is_n
 * @return t_stack*
 */
t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

/**
 * @brief Get the last element of the stack.
 *
 * @param t_stack* stack
 * @return t_stack*
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
 * @param t_stack** stack
 * @param t_stack* new
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
