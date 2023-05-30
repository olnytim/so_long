#include "./mlx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    void	*img;
    void	*img1;
    char	*wall;
    char	*field;

}				t_vars;

int	close(int keycode, t_vars *vars)
{
    printf("key_hook :%d:\n", keycode);
    if(keycode == 65307)
    {
	    mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
	return (0);
}

int	main(void)
{
	t_vars	vars;
    int		width;
	int		height;

    vars.wall = "../phs/walls.xpm";
    vars.field = "../phs/floor.xpm";
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 300, 300, "MLX_TEST");
    vars.img = mlx_xpm_file_to_image(vars.mlx, vars.wall, &width, &height);
    vars.img1 = mlx_xpm_file_to_image(vars.mlx, vars.field, &width, &height);
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 100);
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 100, 0);
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img1, 100, 100);
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 200);
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 100, 200);
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 200, 200);
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 200, 0);
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 200, 100);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
