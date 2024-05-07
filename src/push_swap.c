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

static int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/**
 * @brief Sort the stack using the insertion sort algorithm.
 *
 * @param t_stack** stack_a
 * @param t_stack** stack_b
 */
void	insertion_sort(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a)
		pb(stack_a, stack_b);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		if (*stack_a && (*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	if (is_sorted(*stack_a))
		return ;
	insertion_sort(stack_a, stack_b);
}

/*
void merge_combine(t_stack **stack_a, t_stack **stack_b)
{
    int size_a;
    int size_b;
    int i;
    int j;

    size_a = stack_size(*stack_a);
    size_b = stack_size(*stack_b);
    i = 0;
    j = 0;
    while (i < size_a && j < size_b)
    {
        if ((*stack_a)->value < (*stack_b)->value)
        {
            pa(stack_a, stack_b);
            i++;
        }
        else
        {
            pb(stack_a, stack_b);
            j++;
        }
    }
    while (i < size_a)
    {
        pa(stack_a, stack_b);
        i++;
    }
}
 */

int stack_max(t_stack *stack)
{
    int max;

    if (!stack)
        return (-1);
    max = stack->value;
    while (stack)
    {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return max;
}

/**
 * @brief Sort the stack using the radix sort algorithm.
 *
 * @param t_stack** stack_a
 * @param t_stack** stack_b
 */
void radix_sort(t_stack **a, t_stack **b) {
    int max_num = stack_max(*a);
    int max_bits = 0;
    while ((max_num >> max_bits) != 0) {
        max_bits++;
    }

    for (int i = 0; i < max_bits; i++) {
        int size = 0;
        t_stack *temp = *a;
        while (temp) {
            temp = temp->next;
            size++;
        }
        for (int j = 0; j < size; j++) {
            int num = (*a)->value;
            if ((num >> i) & 1)
                ra(a);
            else
                push(b, pop(a));
            temp = *a;
        }
        while (*b != NULL) {
            push(a, pop(b));
        }
    }
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
    if (is_sorted(*stack_a))
        return ;
    radix_sort(stack_a, stack_b);
}