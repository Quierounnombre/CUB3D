/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_mayus_or_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:03:24 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/03 17:05:34 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	ft_is_mayus_or_num(char c)
{
	if (ft_ismayus(c) || ft_isdigit(c))
		return (true);
	return (false);
}
