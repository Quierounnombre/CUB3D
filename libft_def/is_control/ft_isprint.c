/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IsControl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:20:28 by vicgarci          #+#    #+#             */
/*   Updated: 2022/09/18 00:45:52 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	ft_isprint(int c)
{
	if (c >= 040 && c <= 0176)
		return (true);
	return (false);
}
