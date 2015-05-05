/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:12:24 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:12:24 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void				draw_text(int const x, int const y,
							char const *text, void *font)
{
	int			i;
	int	const	len = slen(text);

	glRasterPos2i(x, y);
	i = -1;
	while (++i < len)
		glutBitmapCharacter(font, text[i]);
}
