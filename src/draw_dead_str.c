/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_dead_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 19:10:30 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/04 19:10:31 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void				draw_dead_str(t_core *c)
{
	int				i;
	int				x;
	int				y;
	char			*tmp;

	glColor3f(0.0f, 0.0f, 0.0f);
	x = c->g.p_padding;
	y = 350;
	i = -1;
	while (++i < PN)
	{
		if (c->p[i].state == DEAD)
		{
			tmp = itoa(c->p[i].i + 1);
			draw_text(x, y, "Philosopher ", F1);
			draw_text(x + 95, y, tmp, F1);
			draw_text(x + 100 + slen(tmp) * 5, y, " died !", F1);
			free(tmp);
			y += 30;
		}
	}
}
