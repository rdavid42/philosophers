/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:12:08 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:12:09 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "core.h"

int					init_core(t_core *core)
{
	if (PN < 2 || PN > 20)
		return (!write(2, "Wrong number of philosophers ! [2..20]\n", 39));
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return (sdl_error(0));
	core->width = 1920;
	core->height = 1080;
	if (!(core->window = SDL_CreateWindow("Philosophers",
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									core->width,
									core->height,
									SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE)))
		return (sdl_error(0));
	if (!(core->context = SDL_GL_CreateContext(core->window)))
		return (sdl_error(0));
	SDL_SetWindowTitle(core->window, "Philosophers");
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	core->stop_sim = 0;
	core->dead_count = 0;
	return (1);
}
