/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:09:25 by julthoma          #+#    #+#             */
/*   Updated: 2024/05/21 18:09:25 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swap bits from start to stop.
 *
 * @param n
 * @param start
 * @param stop
 */
static int	swap_bits(int n, int start, int stop)
{
	int	mask;
	int	i;

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
 * @brief Get total bits used to represent a number.
 *
 * @param n
 */
int	max_bits(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n >> 1;
		i++;
	}
	return (i);
}

/**
 * @brief Transform bits to support negative numbers.
 *
 * @param n
 * @param max_bit
 * @param min_bit
 * @return
 */
int	transform(int n, int max_bit, int min_bit)
{
	int	res;

	res = n;
	if (res < 0)
	{
		res = ~(-res);
		if (res == n)
			res ^= (1L << 31);
		else
			res = swap_bits(res, min_bit, max_bit);
	}
	else
		res ^= (1L << max_bit);
	return (res);
}
