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
 * @brief Sort the stack equal to or smaller than 3.
 *
 * @param stack_a
 */
static void	tiny_sort(t_stack **stack_a)
{
	int		max;

	if (is_sorted(*stack_a))
		return ;
	max = stack_max(*stack_a);
	if ((*stack_a)->value == max)
		ra(stack_a, 1);
	else if ((*stack_a)->next->value == max)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
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
			pb(stack_a, stack_b, 1);
		else
			ra(stack_a, 1);
	}
	tiny_sort(stack_a);
	while (*stack_b)
	{
		if ((*stack_b)->value == max)
		{
			pa(stack_a, stack_b, 1);
			ra(stack_a, 1);
			pa(stack_a, stack_b, 1);
		}
		else
			rb(stack_b);
	}
	pa(stack_a, stack_b, 1);
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
			pb(stack_a, stack_b, 0);
		else
			ra(stack_a, 0);
	}
	while (*stack_b)
		pa(stack_a, stack_b, 0);
}

/**
 * @brief Index the stack starting from smallest value.
 * @param stack
 */
static void index_stack(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    int i;

    i = 0;
    tmp = *stack_a;
    while (tmp)
    {
        tmp->init_index = i++;
        tmp = tmp->next;
    }
    medium_sort(stack_a, stack_b);
    i = 0;
    tmp = *stack_a;
    while (tmp)
    {
        tmp->index = i++;
        tmp = tmp->next;
    }
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

    index_stack(stack_a);
	i = 0;
	while (i < 32 && !is_sorted(*stack_a))
	{
		size = stack_size(*stack_a);
		while (size-- > 0)
		{
			if ((*stack_a)->index & (1 << i))
				ra(stack_a, 1);
			else if (size > 0)
				pb(stack_a, stack_b, 1);
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b, 1);
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
	int	size;

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
