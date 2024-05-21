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


static void print_binary(int n)
{
    int i;

    i = 31;
    while (i >= 0)
    {
        if (n & (1 << i))
            ft_printf("1");
        else
            ft_printf("0");
        if (i % 8 == 0 && i != 0)
            ft_printf(" ");
        i--;
    }
}

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
		ra(stack_a);
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
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	tiny_sort(stack_a);
	while (*stack_b)
	{
		if ((*stack_b)->value == max)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			pa(stack_a, stack_b);
		}
		else
			rb(stack_b);
	}
	pa(stack_a, stack_b);
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
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

/**
 * @brief Index the stack starting from smallest value.
 * @param stack
 */
static void index_stack(t_stack *stack)
{

}

int    translate(int start) {
    int res;
    int i;

    i = 0;
    res = 0;
    while (i < 31) {
        res <<= 1;
        if (start & 1)
            res |= 1;
        start >>= 1;
        i++;
    }
    return (res);
}

unsigned int invertBits(unsigned int num) {
    unsigned int NO_OF_BITS = sizeof(num) * 8;
    unsigned int inverted_num = 0;
    for (int i = 0; i < NO_OF_BITS; i++) {
        if (num & (1 << i))
            inverted_num |= 1 << ((NO_OF_BITS - 1) - i);
    }
    return inverted_num;
}

static int slide_bits(int n, int i)
{
    int tmp;

    tmp = n >> i;
    while (i > 0)
    {
        //set bit at i-th position
        if (tmp & (1 << (i + 1)))
            tmp = tmp ^ (1L << (i + 1));
        i--;
    }
    return (tmp >> i);
}

static void print_stack(t_stack *stack)
{
    while (stack)
    {
        ft_printf("%d (" , stack->value);
        print_binary(stack->value);
        ft_printf(")\n");
        stack = stack->next;
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
    int max_bit;
    int min_bit;
    int min_bit_m;
    int conv;
    int tmp;
    int min;
    int yy;
    int max;

    min = stack_min(*stack_a);
    max = stack_max(*stack_a);
    //ft_printf("max = %d\n", max);
    max_bit = 0;
    while (max > 0)
    {
        max = max >> 1;
        max_bit++;
    }
    min = -min;
    min_bit = 0;
    while (min > 0)
    {
        min = min >> 1;
        min_bit++;
    }


    min = stack_min(*stack_a);
    min = -min;
    min = translate(min);
    min_bit_m = 0;
    while (min > 0)
    {
        min = min >> 1;
        min_bit_m++;
    }

    i = 0;
    if (min_bit > max_bit)
        max_bit = min_bit;
    //ft_printf("max_bit = %d\n", max_bit);
	while (i <= max_bit) {
        size = stack_size(*stack_a);
        while (size-- > 0) {
            tmp = (*stack_a)->value;
            /*
			ft_printf("%d (", tmp);
			print_binary(tmp);
			ft_printf(") ------------>");

			ft_printf("%d (", ft_translate(-tmp));
			print_binary(ft_translate(-tmp));
			ft_printf(") ------------>");
             */
            if (tmp < 0) {
                //tmp = -tmp;
                tmp = tmp;
                yy = 1L;
                /*tmp = translate(tmp);
                conv = 0;
                while (conv < 32)
                {
                    if (tmp & (1 << conv))
                        break ;
                    conv++;
                }
                tmp = (tmp >> min_bit_m);
                yy = 1L;

                max = tmp;
                conv = 0;
                while (max > 0)
                {
                    max = max >> 1;
                    conv++;
                }*/
            } else {
                yy = 1L;
                tmp = tmp | (1L << (max_bit)); // ^
            }
            //ft_printf(" %d (", tmp);
            //print_binary(tmp);
            //ft_printf(")\n");
            if (tmp & (yy << i))
                ra(stack_a);
            else if (size > 0)
                pb(stack_a, stack_b);
        }
        while (*stack_b != NULL)
            pa(stack_a, stack_b);
        i++;
    }
    print_stack(*stack_a);
    size = stack_size(*stack_a);
    while (size-- > 0)
    {
        tmp = (*stack_a)->value;
        if (tmp & (1L << 31))
        {
            pb(stack_a, stack_b);
            //ft_printf("pb tmp : %d\n", tmp);
        }
        else if (size > 0)
        {
            ra(stack_a);
            //ft_printf("ra tmp : %d\n", tmp);
        }
    }
    while (*stack_b != NULL)
        pa(stack_a, stack_b);
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
	/*size = stack_size(*stack_a);
	if (size <= 3)
		tiny_sort(stack_a);
	else if (size <= 5)
		small_sort(stack_a, stack_b);
	else if (size <= 30)
		medium_sort(stack_a, stack_b);
	else*/
		radix_sort(stack_a, stack_b);
}
