/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pythagoras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:12:52 by vicgarci          #+#    #+#             */
/*   Updated: 2023/11/30 14:28:02 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#define ERROR_PYTHAGORAS "Either Hypotenuse is '0' and a side is '0', or both \
sides are '0'.\n"

static void	check_params(size_t side_1, size_t side_2, size_t hypotenuse)
{
	if (side_1 == 0 && hypotenuse == 0)
	{
		ft_printf(ERROR_PYTHAGORAS);
		exit(0);
	}
	if (side_2 == 0 && hypotenuse == 0)
	{
		ft_printf(ERROR_PYTHAGORAS);
		exit(0);
	}
	if (side_1 == 0 && side_2 == 0)
	{
		ft_printf(ERROR_PYTHAGORAS);
		exit(0);
	}
}

/*
@param side_1 side of a triangle, cant be < 0
@param side_2 side of a triangle, cant be < 0
@param hypotenuse the hypothenuse, cant be < 0
@brief Return the unknow side of the triangle, leave that parameter at 0,
if you let 2 params or more at 0 it would exit.
*/
int	ft_pythagoras(size_t side_1, size_t side_2, size_t hypotenuse)
{
	int		res;
	int		tmp;

	res = 0;
	tmp = 0;
	check_params(side_1, side_2, hypotenuse);
	if (side_1 == 0 || side_2 == 0)
	{
		if (side_1 != 0)
			tmp = side_1;
		else
			tmp = side_2;
		res = sqrt(pow(tmp, 2) + pow(hypotenuse, 2));
	}
	else
		res = sqrt(pow(side_1, 2) + pow(side_2, 2));
	return (res);
}
