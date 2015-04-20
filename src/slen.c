/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slen.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 22:13:01 by rdavid            #+#    #+#             */
/*   Updated: 2015/04/20 22:13:01 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int			slen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}