/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:44:01 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/08 09:28:08 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <unistd.h>
# include <mlx.h>
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# define FOFV  60 * M_PI /180
# define T_HEIGHT  80
# define T_WIDTH  80
# define MX	1600
# define MY	900

int					g_save;

typedef struct		s_bitmap
{
	unsigned int	image_width;
	unsigned int	image_height;
	unsigned short	bpp;
	int				width_in_bytes;
	unsigned int	image_size;
	unsigned int	file_size;
	unsigned int	pd_offset;
	unsigned int	header_size;
	unsigned short	planes;

}					t_bitmap;

int					*g_north_texture;
int					*g_south_texture;
int					*g_west_texture;
int					*g_east_texture;
int					*g_sprite_texture;
void				*g_img;
float				*g_buffer;
float				g_xsprite;
float				g_ysprite;
float				g_xspritev;
float				g_yspritev;

typedef struct		s_l
{
	int				fd;
	char			*line;
	char			*ptr;
}					t_l;

typedef struct		s_k
{
	int				i;
	int				k;
	int				j;
	int				m;
}					t_k;

typedef struct		s_m
{
	int				w;
	int				h;
	void			*t;
	int				n;
	int				sln;
}					t_m;

typedef struct		s_point
{
	float				x;
	float				y;
}					t_point;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	int				win_width;
	int				win_height;
	int				map_width;
	int				map_height;
	int				wall_height;
	char			**map;
	t_point			pos_player;
	float			ang_rotation;
	int				turndirection;
	int				walkdirection;
	float			movespeed;
	float			rotationspeed;
	t_point			direction;
	char			*texture1;
	char			*texture2;
	char			*texture3;
	char			*texture4;
	char			*stexture;
	unsigned int	color_floor;
	unsigned int	color_celling;
	int				movestep;
}					t_data;

typedef struct		s_sprite
{
	int				foundvs;
	int				foundhs;
	t_point			hitvs;
	t_point			hiths;
	float			wallhitxs;
	float			wallhitys;
	t_point			intesrsp;
	float			distfs;
	float			raydists;
	int				*texture;
	t_point			p0;

}					t_sprite;

typedef struct		s_ray
{
	int				column;
	float			distance;
	float			ray_angl;
	int				foundh;
	int				foundv;
	float			wallhitx;
	float			wallhity;
	float			m;
	float			ms;
	float			b1;
	float			b2;
	t_sprite		sprite;
}					t_ray;

t_ray				*g_tabl_rays;
t_ray				*g_tabl_rays_sprite;

typedef struct		s_texture_valid
{
	int				no;
	int				so;
	int				we;
	int				ea;
	int				s;
	int				f;
	int				c;
}					t_texture_valid;

typedef struct		s_wh_map
{
	int				i;
	int				j;
	int				k;
}					t_wh_map;

typedef struct		s_intersh
{
	int				x;
	int				y;
	float			xintercept;
	float			yintercept;
	float			nexthortx;
	float			nexthorty;
	float			xstep;
	float			ystep;
}					t_intersh;

typedef struct		s_intersv
{
	int				x;
	int				y;
	float			xintercept;
	float			yintercept;
	float			nextvertx;
	float			nextverty;
	float			xstep;
	float			ystep;
}					t_intersv;

typedef struct		s_rend
{
	int				i;
	int				j;
	float			pwallheigh;
	float			distfpp;
	float			wallbpixl;
	float			walltoppxl;
	float			fcr;
	unsigned int	color;
	int				offy;
	int				offx;
	int				var;
	float			pspriteheigh;
}					t_rend;

int					ft_atoi(const char *str);
void				normalize_angl(t_ray *ray);
int					rayfacingdown(t_ray *ray);
int					rayfacingup(t_ray *ray);
int					rayfacingreight(t_ray *ray);
int					rayfacingleft(t_ray *ray);
float				ft_distance(float x1, float y1, float x2, float y2);
t_point				init_point(float x, float y);
t_point				ft_pos_player(t_data *data);
void				direction_precision(t_data *data);
int					data_init(t_data *data);
void				get_positionsprite(t_data *data, int x, int y);
void				affect_hp(t_ray *ray, t_point *wallhith,
t_intersh *intersh);
void				affect_vp(t_ray *ray, t_point *wallhitv, t_intersv
*intersv);
void				affect_hps(t_data *data, t_ray *ray, t_point *hiths,
t_intersh *intersh);
void				affect_vps(t_data *data, t_ray *ray, t_point *hitvs,
t_intersv *intersv);
void				ft_hendelverticalinters(t_data *data, t_ray *ray,
t_point *wallhitv);
void				ft_hendelhorizontalinters(t_data *data, t_ray *ray,
t_point *wallhith);
void				ft_castrayswalls(t_data *data);
void				ft_renderprojectionwall(t_data *data);
void				init_intersh(t_data *data, t_ray *ray, t_point *wallhith,
t_intersh *intersh);
void				init_intersv(t_data *data, t_ray *ray, t_point *wallhitv,
t_intersv *intersv);
void				ft_hendelhorizontalinterssprite(t_data *data, t_ray *ray,
t_point *hiths);
void				ft_hendelverticalinterssprite(t_data *data, t_ray *ray,
t_point *hitvs);
void				ft_castrayssprite(t_data *data);
void				ft_renderprojectionsprite(t_data *data);
void				ft_rendering(t_data *data);
int					put_color_in_image(int x, int y, int color, t_data *data);
int					release_hook(int key, t_data *data);
int					key_hook(int key, void *param);
int					key_pressed(int key, t_data *data);
int					get_resolution(t_data *data, int *i);
int					ft_map(t_data *data, int i, int j, int k);
int					check_valid_map(t_data *data, t_wh_map *wh_map);
void				check_textures_ns(t_data *data, t_texture_valid *validtxt,
char *ptr, int cas);
void				check_textures_ews(t_data *data, t_texture_valid *validtxt,
char *ptr, int cas);
int					get_textures(t_data *data, t_texture_valid *validtxt);
int					check_color_f(t_data *data, t_texture_valid *validtxt,
char *ptr);
int					check_color_c(t_data *data, t_texture_valid *validtxt,
char *ptr);
int					get_color(t_data *data, t_texture_valid *validtxt);
void				init_angl_and_pos(t_data *data, int i, int j,
t_wh_map *wh_map);
int					get_positionplayer(t_data *data, t_wh_map *wh_map);
char				*ft_strchr(const char *s, int c);
void				print_map(t_data *data);
char				*buf(int n);
char				*ft_itoa(int n);
void				init_validt(t_texture_valid *validtxt);
void				init_wh_map(t_wh_map *wh_map);
int					get_wh_map(t_data *data, t_wh_map *wh_map);
int					expose(void *param);
void				init_datasturct(t_data *data);
void				ft_rayinit(t_data *data, t_ray *ray);
void				init_ray(t_ray *ray);
int					ft_erreur_key(void);
int					ft_erreur_orien(void);
int					ft_erreur_res(void);
int					ft_erreur_walls(void);
int					ft_isprint(int c);
int					ft_erreur_plus(void);
int					ft_detect_car(char *ptr);
int					erreur_path(void);
int					ft_window(t_data *data);
int					allocation_map(t_data *data);
int					ft_resol(t_data *data, t_l *t);
void				ft_wh_map(t_wh_map *wh_map, t_l *t, int *m);
void				ft_help_renderw(t_data *data, t_rend *rd);
void				ft_help_renderw2(t_data *data, t_rend *rd);
void				ft_help_renders(t_data *data, t_rend *rd);
void				set_bmp_header(unsigned char *buff, t_bitmap *bmp,
t_data *data);
void				put_color_buff(unsigned char *buffer, t_bitmap *bmp,
t_data *data);
void				init_header(unsigned char *header);
int					create_bmp(t_data *data);
int					get_color_off_image(int x, int y);
void				decimal_to_rgb(int color, int *color1, int *color2,
int *color3);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
unsigned char		*ft_realloc(unsigned char *buffer, int old_size,
int new_size);
int					ft_cub3d(void);
int					move_player(void *param);
char				*ft_split(char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					erreur_arg(int cas);
int					ft_loop(t_data *data);
int					get_reshelp(t_data *data, t_l *t, int *k);
char				**ft_split1(char const *str, char c);
void				checkotherspar(t_data *data, char **line);
int					ft_exit(char **line);
void				helpheckother(char *line, char **datasplitted);
void				exceedspacecommon(char *ptr);
void				helpgetwhmap(t_wh_map *wh_map, t_l *t, int *a);
void				helpgetcolor(t_l *t, t_texture_valid *validtxt,
int *m, int *n);
char				*ft_strdup(const char *src);
int					ft_helpcolor(char *line, char *ptr);
void				exceedspace(char **ptr);

#endif
