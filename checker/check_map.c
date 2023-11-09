#include "../Cub3D.h"

int	get_max_char(char **dump, int map_lines)
{
	int	i;
	int	max_char;

	i = map_lines;
	max_char = ft_strlen(dump[i]);
	while (dump[++map_lines])
		if (ft_strlen(dump[i]) > max_char)
			max_char = ft_strlen(dump[i]);
	return (max_char);
}

int	map_line(char **dump)
{
	int		i;
	int		count;
	char	**tmp;

	i = -1;
	count = 0;
	while (dump[++i])
	{
		tmp = ft_split(dump[i], ' ');
		if (tmp[i] == NULL || ft_strncmp(tmp[i], "NO", 2) 
			|| ft_strncmp(tmp[i], "SO", 2) || ft_strncmp(tmp[i], "WE", 2) 
			|| ft_strncmp(tmp[i], "EA", 2))
		{
			count++;
		}
		free_split(tmp);
	}
	return (count);
} 

char **get_map(char **dump, int n_lines)
{
	int		max_char_in_map;
	char	**map;
	int		map_lines;
	int		i;
	int		j;

	i = -1;
	map_lines = map_line(dump);
	max_char_in_map = get_max_char(dump, map_lines);
	map = (char **)malloc((n_lines - map_lines + 1) * sizeof(char *));
	while (++i < map_lines)
		map[i] = (char *)malloc((max_char_in_map + 1) * sizeof(char));
	i = -1;
	while (++i < map_lines)
	{
		j = -1;
		while (++j < ft_strlen(dump[i]))
		{	
			if (dump[i][j] == ' ')
				map[i][j] = 'v';
			else
				map[i][j] = dump[i][j];
		}
		while (j < max_char_in_map)
			map[i][j++] = 'v';
		map[i][j] = '\0';
	}
	map[i] = NULL;
	return (map);
}

t_bool	check_map(char **dump, int n_lines, t_cube *cube)
{
	char	**map;
	int		start_map;
	int		j;
	char	tmp;

	start_map = map_line(dump) - 1;
	j = -1;
	while (dump[++start_map])
	{
		j = -1;
		while (dump[++start_map][++j])
		{
			tmp = dump[++start_map][j];
			if ( tmp != '0' || tmp != '1' || tmp != ' ' || tmp != 'N'
				tmp != 'S' || tmp != 'E' || tmp != 'W')
			{
				return (FALSE);
			}
		}
	}
	return (TRUE);
}

