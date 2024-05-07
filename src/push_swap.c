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
 * @brief Get the size of the stack.
 *
 * @param t_stack* stack
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
 * @brief Get the maximum value of the stack.
 *
 * @param t_stack* stack
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
 * @brief Sort the stack using the radix sort algorithm.
 *
 * @param t_stack** stack_a
 * @param t_stack** stack_b
 */
void	radix_sort(t_stack **a, t_stack **b)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
	int	size;

	max_num = stack_max(*a);
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		size = stack_size(*a);
		j = 0;
		while (++j < size)
		{
			if (((*a)->value >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b != NULL)
			pa(a, b);
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			break ;
		tmp = tmp->next;
	}
	radix_sort(stack_a, stack_b);
}
