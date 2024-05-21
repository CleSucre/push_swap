/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 08:07:20 by julthoma          #+#    #+#             */
/*   Updated: 2024/05/04 08:07:20 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 *
 * @param t_stack** stack_a
 * @param t_stack** stack_b
 */
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	ft_printf("pa\n");
}

/**
 * @brief Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 *
 * @param t_stack** stack_a
 */
void	sa(t_stack **stack_a)
{
	int	tmp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = tmp;
	ft_printf("sa\n");
}

/**
 * @brief Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 *
 * @param t_stack** stack
*/
void	rb(t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*to_free;
	int		tmp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b)->value;
	head = (*stack_b)->next;
	to_free = *stack_b;
	while ((*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = stack_new(tmp);
	*stack_b = head;
	free(to_free);
	ft_printf("rb\n");
}

/**
 * @brief Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 *
 * @param t_stack** stack
*/
void	ra(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*to_free;
	int		tmp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a)->value;
	head = (*stack_a)->next;
	to_free = *stack_a;
	while ((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = stack_new(tmp);
	*stack_a = head;
	free(to_free);
	ft_printf("ra\n");
}

/**
 * @brief Shift up all elements of stack a by 1.
 *
 * @param stack_a** stack_a
 */
void	rra(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*to_free;
	int		tmp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	head = *stack_a;
	while ((*stack_a)->next->next != NULL)
		*stack_a = (*stack_a)->next;
	tmp = (*stack_a)->next->value;
	to_free = (*stack_a)->next;
	(*stack_a)->next = NULL;
	*stack_a = stack_new(tmp);
	(*stack_a)->next = head;
	free(to_free);
	ft_printf("rra\n");
}
