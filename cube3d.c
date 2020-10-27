/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 12:52:24 by vronchin          #+#    #+#             */
/*   Updated: 2020/07/31 12:53:32 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_is_dot_cub(char *config_name, t_data *data)
{
	int	i;

	i = ft_strlen(config_name) - 1;
	if (ft_strlen(config_name) < 5 || \
		config_name[i] != 'b' || config_name[i - 1] != 'u' || \
		config_name[i - 2] != 'c' || config_name[i - 3] != '.')
		ft_display_error(data, "Le fichier de configuration\
		doit etre un .cub !!");
}

int		main(int argc, char **argv)
{
	t_data	data;

	init_var_default(&data);
	if (argc < 2)
		ft_display_error(&data, "	Main: Arguments are missing.\n");
	else if (argc > 3)
		ft_display_error(&data, "	Main: Too many arguments\n");
	if (argc == 3)
	{
		if (!ft_strcmp(argv[2], "--save"))
			data.save = 1;
		else
			ft_display_error(&data, "	Main: Second arg wrong.");
	}
	ft_is_dot_cub(argv[1], &data);
	data.mlx = mlx_init();
	ft_parsing_data(argv[1], &data);
	data.window = mlx_new_window(data.mlx, data.wd_w, data.wd_h, "cube3d");
	data.img.img_ptr = mlx_new_image(data.mlx, data.wd_w, data.wd_h);
	data.img.data = (int*)mlx_get_data_addr(data.img.img_ptr,\
	&data.img.bpp, &data.img.size_l, &data.img.endian);
	ft_put_image(&data);
	mlx_hook(data.window, 2, 1L << 0, ft_event, &data);
	mlx_loop(data.mlx);
	return (1);
}
