/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:12:24 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:12:24 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

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
