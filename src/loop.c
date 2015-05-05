/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:12:12 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:12:12 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "core.h"

int					exit_p(t_core *c)
{
	int				i;
	int				t;

	if (c->stop_sim != 2)
	{
		i = -1;
		while (++i < PN)
			c->p[i].stop = c->p[i].stop != -1 ? 1 : -1;
		t = 0;
		while (t != -PN)
		{
			i = -1;
			t = 0;
			while (++i < PN)
				t += c->p[i].stop;
			dprintf(2, "t: %d\n", t);
			usleep(MW);
		}
		release_resources(c);
		c->stop_sim = 2;
	}
	return (1);
}

int					loop(t_core *c)
{
	SDL_Event		e;
	int				quit;

	quit = 0;
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				return (exit_p(c));
			else if (e.type == SDL_KEYDOWN)
			{
				on_keyboard(&e.key);
				if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					return (exit_p(c));
			}
		}
		if (!c->stop_sim)
			update(c);
		else if (c->stop_sim == 1)
			exit_p(c);
		render(c);
		SDL_GL_SwapWindow(c->window);
	}
	return (1);
}
