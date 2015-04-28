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

void				draw_philosophers(t_core *c)
{
	double const		step = ((PI * 2) / PN);
	double				x;
	double				y;
	double				cr;
	int					i;
	static char const	*state[3] = { "Resting", "Eating", "Thinking" };

	glPushMatrix();
	glTranslatef(c->g.cx, c->g.cy, 0);
	cr = 0;
	i = 0;
	while (i < PN)
	{
		x = sin(cr) * (c->g.t_radius + c->g.p_dist);
		y = cos(cr) * (c->g.t_radius + c->g.p_dist);
		draw_circle(x, y, c->g.p_radius, c->g.circle_p);
		draw_text(x * 1.5 - 30, y * 1.5 - 10, state[c->p[i].state], F1);
		draw_text(x * 1.5 - 30, y * 1.5 - 10 + 20, "life: ", F1);
		draw_text(x * 1.5 - 30 + 40, y * 1.5 - 10 + 20,
				itoa(c->p[i].life), F1);
		cr += step;
		i++;
	}
	glPopMatrix();
}

void				render(t_core *c)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gl_enable_2d(0, 0);
	glColor3f(0.0f, 0.0f, 0.0f);

	draw_philosophers(c);

	draw_circle(c->g.cx, c->g.cy, c->g.t_radius, c->g.circle_p);
	gl_disable_2d();
	glFlush();
}
