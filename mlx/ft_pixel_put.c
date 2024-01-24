/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:52:41 by vicgarci          #+#    #+#             */
/*   Updated: 2023/12/15 17:38:33 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	ft_pixel_put(t_mlx_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->adres + (y * img->line + x * (img->bits_per_pixel / BITE_SIZE));
	*(unsigned int *)dst = color;
}
