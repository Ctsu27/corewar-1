/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:30:00 by kehuang           #+#    #+#             */
/*   Updated: 2018/02/08 15:30:03 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ke_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}