/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:12:24 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:12:24 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "core.h"

void				draw_text(int const x, int const y,
							char const *text, void *font)
{
	int			i;
	int	const	len = slen(text);

	glRasterPos2i(x, y);
	for (i = 0; i < len; ++i)
		glutBitmapCharacter(font, text[i]);
}

void				draw_circle(float cx, float cy, float r, int s)
{
	float		t;
	float		x;
	float		y;
	int			i;

	glBegin(GL_LINE_LOOP);
	i = 0;
	while (i < s)
	{
		t = 2.0f * PI * (float)i / (float)s;
		x = r * cosf(t);
		y = r * sinf(t);
		glVertex2f(x + cx, y + cy);
		i++;
	}
	glEnd();
}

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

void				draw_philosophers(t_core *c)
{
	int						i;
	float					x;
	float					y;
	static char const		*state[3] = { "Resting", "Eating", "Thinking" };

	x = c->g.t_x + c->g.p_radius;
	y = c->g.t_y - c->g.p_radius - c->g.p_padding;
	i = -1;
	while (++i < PN)
	{
		draw_text(x - c->g.p_radius, y - c->g.p_radius - c->g.p_padding, state[c->p[i].state], F1);
		draw_text(x - c->g.p_radius, y - c->g.p_radius - c->g.p_padding + 20, "life: ", F1);
		draw_text(x - c->g.p_radius + 40, y - c->g.p_radius - c->g.p_padding + 20, itoa(c->p[i].life), F1);
		draw_circle(x, y, c->g.p_radius, 20);
		x += c->g.p_radius * 2 + c->g.p_padding;
	}
}

void				draw_sticks(t_core *c)
{
	int				i;
	int				x;
	int				y;
	int				j[2];

	x = c->g.t_x + c->g.s_padding;
	y = c->g.t_y + c->g.s_padding;
	glBegin(GL_LINES);
	i = -1;
	while (++i < PN)
	{
		j[0] = (i - 1) < 0 ? PN - 1 : i - 1;
		j[1] = (i + 1) % PN;
		if ()
		x += c->g.p_radius * 2 + c->g.p_padding;
	}
	glEnd();
}
/*
void				draw_philosophers_circle(t_core *c)
{
	static double const		step = ((PI * 2) / PN);
	double					x[2];
	double					y[2];
	double					cr;
	int						i;
	static float const		df = 1.5; // distance factor
	static char const		*state[3] = { "Resting", "Eating", "Thinking" };

	glPushMatrix();
	glTranslatef(c->g.cx, c->g.cy, 0);
	cr = 0;
	i = -1;
	while (++i < PN)
	{
		x[0] = sin(cr);
		y[0] = cos(cr);
		x[1] = x[0] * (c->g.t_radius + c->g.p_dist);
		y[1] = y[0] * (c->g.t_radius + c->g.p_dist);
		draw_circle(x[1], y[1], c->g.p_radius, c->g.circle_p);
		draw_text(x[1] * df - 30, y[1] * df - 10, state[c->p[i].state], F1);
		draw_text(x[1] * df - 30, y[1] * df - 10 + 20, "life: ", F1);
		draw_text(x[1] * df - 30 + 40, y[1] * df - 10 + 20,
				itoa(c->p[i].life), F1);
		cr += step;
	}
	glPopMatrix();
}
*/
void				render(t_core *c)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gl_enable_2d(0, 0);
	glColor3f(0.0f, 0.0f, 0.0f);
	draw_philosophers(c);
	draw_table(c);
	draw_sticks(c);
	if (c->stop_sim && c->dead_count == 0)
		draw_text(c->width / 2 - 100, c->height - 100, SUCCESS_STR, F1);
	gl_disable_2d();
	glFlush();
}
