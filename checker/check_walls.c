#include "../Cub3D.h"

t_bool	check_north_wall(char **map, int rows, int colums)
{
	int	i;
	int	j;
	t_bool	res;
	
	i = -1;
	j = -1;
	res = FALSE;
	while (++j < colums)
	{
		i = -1;
		while (++i < rows)
			if (map[i][j] == '1')
				res = TRUE;
	}
	return (res);
}

t_bool	check_west_wall(char **map, int rows, int colums)
{
	int	i;
	int	j;
	t_bool	res;
	
	i = -1;
	j = -1;
	res = FALSE;
	while (++i < colums)
	{
		j = -1;
		while (++j < rows)
			if (map[i][j] == '1')
				res = TRUE;
	}
	return (res);
}

t_bool	check_west_east(char **map, int rows, int colums)
{
	int	i;
	int	j;
	t_bool	res;
	
	i = colums - 1;
	j = rows - 1;
	res = FALSE;
	while (i > 0)
	{
		j = rows - 1;
		while (j > 0)
		{
			if (map[i][j] == '1')
				res = TRUE;
			j--:
		}
		i--;
	}
	return (res);
}

t_bool	check_west_east(char **map, int rows, int colums)
{
	int	i;
	int	j;
	t_bool	res;
	
	i = colums - 1;
	j = rows - 1;
	res = FALSE;
	while (j > 0)
	{
		i = rows - 1;
		while (i > 0)
		{
			if (map[i][j] == '1')
				res = TRUE;
			i--:
		}
		j--;
	}
	return (res);
}

t_bool	is_map_closed(char **map, int rows, int cols) 
{
	if (check_north_wall(map, rows, cols) == TRUE
		&& check_south_wall(map, rows, cols) == TRUE
		&& check_west_wall(map, rows, cols) == TRUE
		&& check_east_wall(map, rows, cols) == TRUE)
	{
		return TRUE;
	}
	else
		return FALSE;
}