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
 * @brief Print the stack. For debugging purposes.
 * @param stack
 */
static void	ft_print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		ft_printf("stack[%d] = %d\n", i, stack->value);
		stack = stack->next;
		i++;
	}
}

/**
 * @brief Sort the stack_a using the stack_b.
 * Use the following algorithm: IDK
 *
 * @param stack_a
 * @param stack_b
 */
void	ft_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_b;
	ft_print_stack(*stack_a);
}
