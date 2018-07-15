/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_lst_advance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:00:18 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:45 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			lo_lst_advance(t_list **head, int advance)
{
	if (!head || !*head)
		return (0);
	while (advance > 1)
	{
		if ((*head)->next == NULL)
			return (0);
		*head = (*head)->next;
		--advance;
	}
	return (1);
}
