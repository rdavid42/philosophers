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

#include "core.h"

void				loop(t_core *core)
{
	SDL_Event		e;
	int32_t			quit;

	quit = 0;
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quit = 1;
			else if (e.type == SDL_KEYDOWN)
			{
				on_keyboard(&e.key);
				if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					quit = 1;
			}
		}
		SDL_SetWindowTitle(core->window, "Philosophers");
		update(&core);
		render();
		SDL_GL_SwapWindow(core->window);
	}
}
