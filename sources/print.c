/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:26:04 by mgama             #+#    #+#             */
/*   Updated: 2026/04/20 16:39:19 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void
clear_screen(uint8_t attrib)
{
	volatile uint16_t *buffer = (uint16_t *)VGA_TEXT_BUFFER;
	for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++)
	{
		buffer[i] = (uint16_t)(attrib << 8);
	}
}

void
print_screen(const char *s, uint8_t attrib)
{
    static uint32_t cursor = 0;
    volatile uint16_t *buffer = (uint16_t *)VGA_TEXT_BUFFER;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '\n')
		{
            cursor += VGA_WIDTH - (cursor % VGA_WIDTH);
        }
		else
		{
            buffer[cursor] = (uint16_t)((attrib << 8) | s[i]);
            cursor++;
        }

        if (cursor >= 80 * 25) cursor = 0;
    }
}
