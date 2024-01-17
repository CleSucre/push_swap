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

void    stack_clear(t_stack **stack)
{
	t_stack	*t;

	while (*stack)
	{
		t = (*stack)->next;
                free(*stack);
		(*stack) = t;
	}
}

t_stack	*stack_new(int value)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_stack *stack_last(t_stack *stack)
{
        t_stack	*t;

        if (!stack)
                return (NULL);
        t = stack;
        while (t->next)
                t = t->next;
        return (t);
}

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
		*stack = new;
}

int     swap(t_stack *stack)
{
        t_stack *tmp;

        if (stack == NULL || stack->next == NULL)
                return (1);
        tmp = stack->next;
        stack->next = tmp->next;
        tmp->next = stack;
        stack = tmp;
        return (0);
}

/**
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
*/
int     ra(t_stack *stack)
{
        (void)stack;
        return (0);
}

int     sb(t_stack *stack)
{
        (void)stack;
        return (0);
}

int     ss(t_stack *stack_a, t_stack *stack_b)
{
        (void)stack_a;
        (void)stack_b;
        return (0);
}

int     pa(t_stack *stack_a, t_stack *stack_b)
{
        (void)stack_a;
        (void)stack_b;
        return (0);
}

int     pb(t_stack *stack_a, t_stack *stack_b)
{
        (void)stack_a;
        (void)stack_b;
        return (0);
}

int     rb(t_stack *stack)
{
        (void)stack;
        return (0);
}

int     rr(t_stack *stack_a, t_stack *stack_b)
{
        (void)stack_a;
        (void)stack_b;
        return (0);
}

int     rra(t_stack *stack)
{
        (void)stack;
        return (0);
}

int     rrb(t_stack *stack)
{
        (void)stack;
        return (0);
}

int     rrr(t_stack *stack_a, t_stack *stack_b)
{
        (void)stack_a;
        (void)stack_b;
        return (0);
}
