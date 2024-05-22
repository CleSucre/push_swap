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

int	swap_bits(int n, int start, int stop)
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
