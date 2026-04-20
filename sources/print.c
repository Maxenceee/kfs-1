/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:26:04 by mgama             #+#    #+#             */
/*   Updated: 2026/04/20 14:28:07 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <types.h>

#define VGA_TEXT_BUFFER 0xb8000u

void
printk(const char *s, uint8_t attrib)
{
	volatile uint16_t *vp = (uint16_t *)VGA_TEXT_BUFFER;
	while (*s)
	{
		*vp = (attrib << 8) | *s++;
	}
}
