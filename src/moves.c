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

int     swap(t_list *stack)
{
        t_list *tmp;

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
int     ra(t_list *stack)
{
        (void)stack;
        return (0);
}

int     sb(t_list *stack)
{
        (void)stack;
        return (0);
}

int     ss(t_list *stack_a, t_list *stack_b)
{
        (void)stack_a;
        (void)stack_b;
        return (0);
}

int     pa(t_list *stack_a, t_list *stack_b)
{
        (void)stack_a;
        (void)stack_b;
        return (0);
}

int     pb(t_list *stack_a, t_list *stack_b)
{
        (void)stack_a;
        (void)stack_b;
        return (0);
}

int     rb(t_list *stack)
{
        (void)stack;
        return (0);
}

int     rr(t_list *stack_a, t_list *stack_b)
{
        (void)stack_a;
        (void)stack_b;
        return (0);
}

int     rra(t_list *stack)
{
        (void)stack;
        return (0);
}

int     rrb(t_list *stack)
{
        (void)stack;
        return (0);
}

int     rrr(t_list *stack_a, t_list *stack_b)
{
        (void)stack_a;
        (void)stack_b;
        return (0);
}
