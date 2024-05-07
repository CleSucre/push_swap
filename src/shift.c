/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 08:07:14 by julthoma          #+#    #+#             */
/*   Updated: 2024/05/08 00:52:17 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 *
 * @param t_stack** stack
*/
void	ra(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("ra\n");
}

/**
 * @brief Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 *
 * @param t_stack** stack
 */
void	rra(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = stack_last(*stack);
	tmp = *stack;
	*stack = (*stack)->next;
	last->next = tmp;
	tmp->next = NULL;
	ft_printf("rra\n");
}

/**
 * @brief Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 *
 * @param t_stack** stack
 */
void	rrb(t_stack **stack)
{
	rra(stack);
	ft_printf("rrb\n");
}

/**
 * @brief Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 *
 * @param t_stack** stack
 */
void	rb(t_stack **stack)
{
	ra(stack);
	ft_printf("rb\n");
}

/**
 * @brief ra and rb at the same time
 *
 * @param t_stack** stack_a
 * @param t_stack** stack_b
 */
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

/**
 * @brief rra and rrb at the same time.
 *
 * @param t_stack** stack_a
 * @param t_stack** stack_b
 */
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
