/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:55:17 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:51 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long	lo_power(long long n, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return ((long long)1);
	else if (power == 1)
		return (n);
	return (n * lo_power(n, power - 1));
}
