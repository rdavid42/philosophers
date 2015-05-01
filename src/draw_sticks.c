/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sticks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:12:24 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:12:24 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static void			draw_stick_no_owner(t_core *c, float x, float y)
{
	glVertex2f(x, y);
	glVertex2f(x, y - c->g.s_size);
}

static void			draw_stick_right_owner(t_core *c, float x, float y)
{
	glVertex2f(x - c->g.s_padding, y + c->g.p_padding);
	glVertex2f(x - c->g.s_padding, y + c->g.p_padding - c->g.s_size);
}

static void			draw_stick_left_owner(t_core *c, float x, float y)
{
	glVertex2f(x + 2 * c->g.p_radius - c->g.s_padding,
				y + c->g.p_padding);
	glVertex2f(x + 2 * c->g.p_radius - c->g.s_padding,
				y + c->g.p_padding - c->g.s_size);
}

void				draw_sticks(t_core *c)
{
	int						i;
	int						x;
	int						y;
	int						l;
	int						inc;

	x = c->g.t_x + c->g.s_padding;
	y = c->g.t_y + c->g.s_padding + c->g.t_height;
	inc = c->g.p_radius * 2 + c->g.p_padding;
	glBegin(GL_LINES);
	i = -1;
	while (++i < PN)
	{
		l = (i - 1) < 0 ? PN - 1 : i - 1;
		if (c->s[i].owner == -1)
			draw_stick_no_owner(c, x + i * inc, y);
		else if (c->s[i].owner == i)
			draw_stick_right_owner(c, x + i * inc, y);
		else if (c->s[i].owner == l)
			draw_stick_left_owner(c, x + l * inc, y);
	}
	glEnd();
}
