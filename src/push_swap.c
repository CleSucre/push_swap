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

static int max_bits(int n)
{
    int i;

    i = 0;
    while (n > 0)
    {
        n = n >> 1;
        i++;
    }
    return (i);
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

static int slide_right_bits(int n, int i)
{
    int tmp;

    tmp = n >> i;
    while (i > 0)
    {
        if (tmp & (1 << (i + 1)))
            tmp = tmp ^ (1L << (i + 1));
        i--;
    }
    return (tmp >> i);
}

static int slide_left_bits(int n, int i)
{
    int tmp;

    tmp = n << i;
    while (i > 0)
    {
        if (tmp & (1 << (i + 1)))
            tmp = tmp ^ (1L << (i + 1));
        i--;
    }
}

static void debug(int n)
{
    print_binary(n);
    ft_printf(" : %d\n", n);
}

static int swap_all_bits(int n)
{
    return (translate(n) >> (31 - max_bits(n)));
}

/*
static int swap_bits(int n, int i)
{
    return (translate(n) >> (31 - i));
}
 */

static int swap_bits(int n, int start, int stop)
{
    //turn swap all bits from start to stop
    int mask;
    int i;

    i = 0;
    mask = 0;
    while (i < 32)
    {
        if (i >= start && i <= stop)
            mask |= 1 << i;
        i++;
    }
    return (n & ~mask);
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
    int modulo;
    int is_modulo;
    int yy;
    int max;

    is_modulo = !(min % 2);
    max_bit = max_bits(stack_max(*stack_a));
    min_bit = max_bits(-stack_min(*stack_a));
    //min_bit_m = max_bits(translate((-stack_min(*stack_a))));
    if (min_bit > max_bit)
        max_bit = min_bit;

    //ft_printf("is_modulo = %d\n", is_modulo);
    //ft_printf("max_bit = %d & min_bit = %d\n", max_bit, min_bit);

    i = 0;
	while (i <= max_bit && !is_sorted(*stack_a))
	{
		size = stack_size(*stack_a);
		while (size-- > 0)
		{
			tmp = (*stack_a)->value;
			if (tmp < 0)
            {
                tmp = -tmp;

                modulo = !(tmp % 2);
                yy = max_bits(tmp);

                tmp = ~tmp;
                tmp = swap_bits(tmp, min_bit, max_bit);

                /*
                if (modulo)
                {
                    tmp = tmp | (1L << 0);
                }
                 */
                /*
                yy = max_bits(tmp);
                tmp = swap_bits(tmp, min_bit);
                if (!modulo && yy != min_bit)
                {
                    tmp = tmp << 1;
                }
                debug(tmp);
                 */
                /*
                if (modulo)
                {
                    ft_printf("min_bit %d - yy %d - modulo %d total %d\n", min_bit, yy, modulo, min_bit - yy - modulo);
                    tmp = tmp << (min_bit - yy - modulo);
                }
                else
                {
                    tmp = swap_bits(tmp);
                    tmp = tmp;
                }
                 */
            }
			else
            {
                tmp ^= (1L << max_bit);
            }
			if (tmp & (1L << i))
				ra(stack_a);
			else if (size > 0)
				pb(stack_a, stack_b);
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b);
		i++;
	}
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
