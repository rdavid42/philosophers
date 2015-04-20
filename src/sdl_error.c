/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:12:57 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:12:58 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "core.h"

int				sdl_error(int code)
{
	char const	*err = SDL_GetError();

	write(2, "SDL Error: ", 11);
	write(2, err, slen((char *)err));
	write(2, "\n", 1);
	return (code);
}
