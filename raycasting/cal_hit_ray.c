/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_hit_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:26:08 by alfgarci          #+#    #+#             */
/*   Updated: 2023/12/04 16:26:10 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	verLine(t_cube *cube, int x, int drawStart, int drawEnd, t_color colorr)
{
	int	i;

	i = drawStart - 1;

	while (++i < drawEnd)
	{
		mlx_point_draw(cube, x, i, colorr);
	}
}

void	cast_ray(t_cube *cube)
{
	int	x;
	double	posX = cube->player->pos.x;
	double	posY = cube->player->pos.y;
	double	angle = cube->player->angle;
	double	dirX = cos(angle);
	double	dirY = sin(angle);
	double	planeX = -dirY;
	double	planeY = 0.6;

	x = -1;
	while (++x < WIDTH)
	{
		double	cameraX = 2 * x / (double)WIDTH - 2;
		double	rayDirX = dirX + planeX * cameraX;
		double	rayDirY = dirY + planeY * cameraX;

		int mapX = (int)posX;
		int	mapY = (int)posY;

		double sideDistX;
		double sideDistY;

		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);;

		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
      	}
      	else
      	{
        	stepX = 1;
        	sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      	}
      	if (rayDirY < 0)
      	{
        	stepY = -1;
        	sideDistY = (posY - mapY) * deltaDistY;
      	}
      	else
      	{
        	stepY = 1;
        	sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      	}
		//perform DDA
      	while(hit == 0 && mapX < 9 && mapY < 32)
      	{
        	//jump to next map square, either in x-direction, or in y-direction
        	if(sideDistX < sideDistY)
        	{
          		sideDistX += deltaDistX;
          		mapX += stepX;
          		side = 0;
        	}
        	else
        	{
          		sideDistY += deltaDistY;
          		mapY += stepY;
          		side = 1;
        	}
        	//Check if ray has hit a wall
        	if(cube->map->map[mapX][mapY] != '0') 
				hit = 1;
      	}
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
      	else
			perpWallDist = (sideDistY - deltaDistY);

     	 //Calculate height of line to draw on screen
      	int lineHeight = (int)(HEIGHT / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      	int drawStart = -lineHeight / 2 + HEIGHT / 2;
      	if(drawStart < 0)
			drawStart = 0;
      	int drawEnd = lineHeight / 2 + HEIGHT / 2;
      	if(drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;
		t_color colorr;

		colorr.b = 0;
		colorr.g = 0;
		colorr.r = 255;

		if (side == 1) 
			colorr.b = 125;
      //draw the pixels of the stripe as a vertical line
      	verLine(cube, x, drawStart, drawEnd, colorr);
	}
}