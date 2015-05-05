/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:12:24 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:12:24 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void				draw_table(t_core *c)
{
	glBegin(GL_LINES);
	glVertex2f(c->g.t_x, c->g.t_y);
	glVertex2f(c->g.t_x + c->g.t_width, c->g.t_y);
	glVertex2f(c->g.t_x + c->g.t_width, c->g.t_y);
	glVertex2f(c->g.t_x + c->g.t_width, c->g.t_y + c->g.t_height);
	glVertex2f(c->g.t_x + c->g.t_width, c->g.t_y + c->g.t_height);
	glVertex2f(c->g.t_x - 1, c->g.t_y + c->g.t_height);
	glVertex2f(c->g.t_x, c->g.t_y + c->g.t_height);
	glVertex2f(c->g.t_x, c->g.t_y);
	glEnd();
}
