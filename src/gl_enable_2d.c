/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_enable_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:12:04 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:12:04 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void			gl_enable_2d(int cam_x, int cam_y)
{
	int			v_port[4];

	glDisable(GL_DEPTH_TEST);
	glGetIntegerv(GL_VIEWPORT, v_port);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(cam_x, v_port[2] + cam_x, v_port[3] + cam_y, cam_y, -0.001, 0.001);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
}
