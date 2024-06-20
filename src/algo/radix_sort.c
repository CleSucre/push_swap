/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   god_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:38:43 by julthoma          #+#    #+#             */
/*   Updated: 2024/01/11 23:38:43 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/**
 * @brief Print the stack for debugging.
 *
 * @param t_stack *stack
 */
void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

/**
 * @brief Index the stack to sort it.
 *
 * @param stack
 * @return void
 */
void	index_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		count;

	tmp = *stack;
	while (tmp)
	{
		count = 0;
		tmp2 = *stack;
		while (tmp2)
		{
			if (tmp->value > tmp2->value)
				count++;
			tmp2 = tmp2->next;
		}
		tmp->index = count;
		tmp = tmp->next;
	}
}

/**
 * @brief Sort the stack using the radix sort algorithm.
 *
 * @param t_stack** stack_a
 * @param t_stack** stack_b
 */
void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bit;
	int	min_bit;
	int	size;
	int	i;

	index_stack(stack_a);
	max_bit = max_bits(stack_max_index(*stack_a));
	min_bit = max_bits(-stack_min_index(*stack_a));
	if (min_bit > max_bit)
		max_bit = min_bit;
	i = 0;
	while (i <= max_bit || !is_sorted(*stack_a))
	{
		size = stack_size(*stack_a);
		while (size-- > 0)
		{
			if ((*stack_a)->index & (1L << i))
				ra(stack_a);
			else if (size > 0)
				pb(stack_a, stack_b);
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b);
		i++;
	}
}