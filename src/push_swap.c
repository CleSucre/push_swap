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
 * @brief Get the maximum value of the stack.
 *
 * @param t_stack* stack
 * @return int
 */
static int	stack_max(t_stack *stack)
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
 * @brief Sort the stack equal to or smaller than 3.
 *
 * @param stack_a
 */
static void	tiny_sort(t_stack **stack_a)
{
    t_stack *tmp;

    if (stack_size(*stack_a) == 2)
    {
        if ((*stack_a)->value > (*stack_a)->next->value)
            sa(stack_a);
        return ;
    }
    tmp = *stack_a;
    else if (stack_size(*stack_a) == 3)
    {
        if ((tmp->index > tmp->next->index && tmp->next->index < tmp->next->next->index
			&& tmp->next->next->index > tmp->index) || (tmp->index > tmp->next->index
			&& tmp->next->index > tmp->next->next->index
			&& tmp->next->next->index < tmp->index) || (tmp->index < tmp->next->index
			&& tmp->next->index > tmp->next->next->index
			&& tmp->next->next->index > tmp->index))
            sa(stack_a);
        tmp = *stack;
        if (tmp->index > tmp->next->index && tmp->next->index < tmp->next->next->index
		&& tmp->next->next->index < tmp->index)
	    {
            sa(stack_a);
        }
        else if ((tmp->index < tmp->next->index && tmp->next->index > tmp->next->next->index
			&& tmp->next->next->index < tmp->index))
            rra(stack_a);
    }
}

static void	small_sort(t_stack **stack_a, t_stack **stack_b)
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
    while (*stack_b)
    {
        if ((*stack_b)->value == min)
            pa(stack_a, stack_b);
        else
            rb(stack_b);
    }
}

/**
 * @brief Sort the stack using a small & basic sort algorithm.
 *
 * @param stack_a* stack_a
 * @param stack_b* stack_b
 */
static void	medium_sort(t_stack **stack_a, t_stack **stack_b)
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
    int size;

	if (is_sorted(*stack_a))
		return ;
    size = stack_size(*stack_a);
	if (size <= 3)
		tiny_sort(stack_a);
	else if (size <= 5)
		small_sort(stack_a, stack_b);
	else if (size <= 30)
		medium_sort(stack_a, stack_b);
    else
		radix_sort(stack_a, stack_b);
}
