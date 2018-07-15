/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_lst_stepback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:00:38 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:12:25 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			lo_lst_stepback(t_list **head, int stepback)
{
	if (!head || !*head)
		return (0);
	while (stepback > 0)
	{
		if ((*head)->prev == NULL)
			return (0);
		*head = (*head)->prev;
		--stepback;
	}
	return (1);
}
