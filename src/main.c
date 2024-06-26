/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:09:25 by julthoma          #+#    #+#             */
/*   Updated: 2024/01/12 18:09:25 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 *
 * @param t_stack** stack_a
 * @param t_stack** stack_b
 */
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	ft_printf("pb\n");
}

/**
 * @brief Get the minimum value of the stack.
 *
 * @param t_stack* stack
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
 * @brief Check if the stack is sorted.
 *
 * @param stack* stack
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc == 1)
		return (1);
	stack_a = ft_parsing((const char **)argv + 1, NULL);
	if (stack_a == NULL)
	{
		ft_fprintf(2, "Error\n");
		return (2);
	}
	stack_b = NULL;
	size = stack_size(stack_a);
	if (size <= 3)
		tiny_sort(&stack_a);
	else if (size <= 5 && !is_sorted(stack_a))
		small_sort(&stack_a, &stack_b);
	else if (size <= 30)
		medium_sort(&stack_a, &stack_b);
	else if (!is_sorted(stack_a))
		radix_sort(&stack_a, &stack_b);
	stack_clear(&stack_a);
	return (0);
}
