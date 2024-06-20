/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 08:07:20 by julthoma          #+#    #+#             */
/*   Updated: 2024/05/04 08:07:20 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 *
 * @param t_stack **stack_b
*/
void	rb(t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*to_free;
	int		tmp;
	int		tmp2;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b)->value;
	tmp2 = (*stack_b)->index;
	head = (*stack_b)->next;
	to_free = *stack_b;
	while ((*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = stack_new(tmp);
	(*stack_b)->next->index = tmp2;
	*stack_b = head;
	free(to_free);
	ft_printf("rb\n");
}

/**
 * @brief Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 *
 * @param t_stack **stack_a
*/
void	ra(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*to_free;
	int		tmp;
	int		tmp2;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a)->value;
	tmp2 = (*stack_a)->index;
	head = (*stack_a)->next;
	to_free = *stack_a;
	while ((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = stack_new(tmp);
	(*stack_a)->next->index = tmp2;
	*stack_a = head;
	free(to_free);
	ft_printf("ra\n");
}

/**
 * @brief Shift up all elements of stack a by 1.
 *
 * @param stack_a **stack_a
 */
void	rra(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*to_free;
	int		tmp;
	int		tmp2;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	head = *stack_a;
	while ((*stack_a)->next->next != NULL)
		*stack_a = (*stack_a)->next;
	tmp = (*stack_a)->next->value;
	tmp2 = (*stack_a)->next->index;
	to_free = (*stack_a)->next;
	(*stack_a)->next = NULL;
	*stack_a = stack_new(tmp);
	(*stack_a)->index = tmp2;
	(*stack_a)->next = head;
	free(to_free);
	ft_printf("rra\n");
}
