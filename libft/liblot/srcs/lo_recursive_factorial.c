/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:44:18 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:55 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		lo_recursive_factorial(int nb)
{
	if (nb == 1 || nb == 0)
		return (1);
	else if (nb < 0 || nb > 12)
		return (0);
	else
		return (nb * (lo_recursive_factorial(nb - 1)));
}
