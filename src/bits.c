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
