/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:42:53 by eriling           #+#    #+#             */
/*   Updated: 2021/04/03 14:45:18 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <comput.h>
#include <struct.h>

int		color_final(double coeff_light, int color_obj, int color_light)
{
	int final_color;
	int color_light_total;
	double coeff_total;

	coeff_total = coeff_light + singleton()->a_ran_light;
	color_light_total = mix_rgb(color_light,rgb_to_int_ambiante(), coeff_light / coeff_total);
	if (coeff_total > 1)
		coeff_total = 1;
	final_color = mix_rgb(color_light_total, color_obj, 0.5);
	final_color = color_coeff(final_color, coeff_total);
	return (final_color);
}

int color_coeff(int color, double coeff)
{
	int r;
	int g;
	int b;

	if (coeff > 1)
		coeff = 1;
	r = (color >> 16) & 0b11111111;
	g = (color >> 8) & 0b11111111;
	b = (color >> 0) & 0b11111111;
	r *= coeff;
	g *= coeff;
	b *= coeff;
	color = (r << 16) + (g << 8) + (b << 0);
	return(color);
}