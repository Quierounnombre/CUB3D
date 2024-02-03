/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_key_to_dic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:22:04 by vicgarci          #+#    #+#             */
/*   Updated: 2024/02/03 17:42:22 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

static void	add_key(t_lstmng *mng, t_list *lst)
{
	if (!mng->current)
	{
		mng->current = lst;
		mng->lst_head = lst;
		mng->size = 1;
		mng->tail = lst;
	}
	else
	{
		mng->size++;
		mng->tail->next = lst;
		mng->tail = lst;
	}
}

static t_list	*make_new_key(t_cube *cube, char *s)
{
	t_list		*lst;
	t_color_key	*key;

	key = NULL;
	lst = NULL;
	key = (t_color_key *)malloc(sizeof(t_color_key));
	if (!key)
	{
		free(s);
		exit_error(ERROR_MALLOC, errno, cube);
	}
	lst = ft_lstnew(key);
	if (!lst)
	{
		free(s);
		exit_error(ERROR_MALLOC, errno, cube);
	}
	return (lst);
}

void	add_new_key_to_dic(t_cube *cube, t_texture *texture, char *s)
{
	t_list	*lst;

	lst = make_new_key(cube, s);
	add_key(texture->color_dictionary, lst);
	parse_pair(cube, s, lst);
}
