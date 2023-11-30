/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_vector2D.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:57:27 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/30 14:58:39 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_vector2D	load_vector2d(int i, int j)
{
	t_vector2D	v;

	v.x = (float)i;
	v.y = (float)j;
	return (v);
}
