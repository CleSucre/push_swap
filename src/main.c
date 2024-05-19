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

	if (argc == 1)
		return (1);
	stack_a = ft_parsing((const char **)argv + 1, NULL);
	if (stack_a == NULL)
	{
		ft_fprintf(2, "Error\n");
		return (2);
	}
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	stack_clear(&stack_a);
	return (0);
}
