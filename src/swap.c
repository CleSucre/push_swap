/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 08:07:25 by julthoma          #+#    #+#             */
/*   Updated: 2024/05/04 08:07:25 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 *
 * @param t_stack** stack
 */
void	sa(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	ft_printf("sa\n");
}

/**
 * @brief Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
 *
 * @param t_stack** stack
 */
void	sb(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	ft_printf("sb\n");
}

/**
 * @brief sa and sb at the same time.
 *
 * @param t_stack** stack_a
 * @param t_stack** stack_b
 */
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	//TODO: remove printf from the functions
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}
