/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:35:53 by kichkiro          #+#    #+#             */
/*   Updated: 2023/10/29 00:18:07 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// Libraries ------------------------------------------------------------------>

# include "minirt.h"

// Defines -------------------------------------------------------------------->

# define EPSILON 0.00001

// Structures ----------------------------------------------------------------->

/*!
 * @brief
	It represents the record of an intersection between a ray and an object in a
	3D scene.
 * @param has_intersec
	Flag indicating whether an intersec occurred.
 * @param point
	The point of intersec in 3D space.
 * @param normal
	The surface normal at the intersec point.
 * @param color
	The color of the surface at the intersec point.
 * @param nearest
  	The nearest intersec distance along the ray.
 * @param min
	Minimum intersec distance to consider.
 * @param max
	Maximum intersec distance to consider.
 */
typedef struct s_intersec
{
	bool		has_intersec;
	t_v3		point;
	t_v3		normal;
	t_rgb		color;
	double		nearest;
	double		min;
	double		max;
}	t_intersec;

typedef struct s_ray
{
	t_v3		origin;
	t_v3		direction;
}	t_ray;

typedef struct s_texture_coords
{
	double	u;
	double	v;
}	t_texture_coords;

/*!
 * @brief 
	This structure contains the lighting information at an intersection point.
 * @param sfactor
	Specular reflection factor.
 * @param dfactor
	Diffuse reflection factor.
 * @param len
	Length of a shadow ray.
 * @param shadow_ray
	Shadow ray.
 * @param ambient
	Ambient light color.
 * @param diffuse
	Diffuse light color.
 * @param light
	Direction to the light source.
 * @param specular
	Specular reflection color.
 * @param viewdir
	Direction to the viewer.
 * @param reflect
	Direction of reflection.
 * @param color
	Final color at the intersection point.
 */
typedef struct s_lighting
{
	double	sfactor;
	double	dfactor;
	double	len;
	t_ray	shadow_ray;
	t_v3	ambient;
	t_v3	diffuse;
	t_v3	light;
	t_v3	specular;
	t_v3	viewdir;
	t_v3	reflect;
	t_v3	color;
}	t_lighting;

/*!
 * @brief 
	Data structure for representing information about ray-object intersections.
 * @param x
	The point where the ray intersects the object.
 * @param p
	The surface normal at the intersection point.
 * @param diff
	The diffuse color of the object at the intersection point.
 * @param pcent
	The intersection point in a centered coordinate system.
 * @param dv
	The distance from the intersection point to the viewer.
 * @param xv
	The x-coordinate of the intersection point.
 * @param a
	The opacity or transparency of the object.
 * @param hb
	A bias to prevent self-intersections.
 * @param c
	The specular coefficient of the object.
 * @param dis
	The distance from the ray origin to the intersection point.
 * @param t
	The time at which the ray first intersects the object.
 * @param t2
	The time at which the ray re-enters the object (if applicable).
 * @param sdis
	The distance to a shadow ray intersection.
 * @param dtop
	The dot product with the object's top surface (if applicable).
 */
typedef struct s_hit
{
	t_v3	x;
	t_v3	p;
	t_v3	diff;
	t_v3	pcent;
	double	dv;
	double	xv;
	double	a;
	double	hb;
	double	c;
	double	dis;
	double	t;
	double	t2;
	double	sdis;
	double	dtop;
}	t_hit;

// Functions ------------------------------------------------------------------>

void	render(t_mlx **mlx, t_scene *scene);
int		raycaster(t_scene *scene, t_camera *cam, int x, int y);
void	lighting(t_scene *scene, t_intersec *isec);
bool	intersections(t_scene *scene, t_ray ray, t_intersec *isec, double len);
void	intersec_init(t_intersec **isec);
bool	intersec_cylinder(t_ray *ray, t_cylinder *cy, t_intersec **isec);
bool	intersec_sphere(t_ray *ray, t_sphere *sp, t_intersec **isec);
bool	intersec_plane(t_ray *ray, t_plane *pl, t_intersec **isec);

int		rgb_to_int(t_rgb *rgb);
int		rgb_to_int2(int r, int g, int b);
void	print_rgb_int(t_rgb *rgb);
void	print_rgb_hex(t_rgb *rgb);
t_rgb	v3_to_rgb(t_v3 v);
t_v3	rgb_to_v3(t_rgb rgb);

#endif
