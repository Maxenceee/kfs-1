/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:26:04 by mgama             #+#    #+#             */
/*   Updated: 2026/04/21 10:31:37 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"
#include "delay.h"

uint16_t cursor_pos = 0;

void
init_screen(void)
{
	cursor_pos = get_cursor_position();
}

void
clear_screen(void)
{
	for (int i = 0; i < VGA_HEIGHT; i++)
	{
		scroll_screen();
	}
	cursor_pos = 0;
	move_cursor(cursor_pos);
}

void
print_dscreen(const char *s, uint8_t attrib, int delay)
{
	volatile uint16_t *buffer = (uint16_t *)VGA_TEXT_BUFFER;
	
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '\n')
		{
			cursor_pos += VGA_WIDTH - (cursor_pos % VGA_WIDTH);
		}
		else
		{
			buffer[cursor_pos] = (uint16_t)((attrib << 8) | s[i]);
			cursor_pos++;
		}
	
		if (cursor_pos >= VGA_WIDTH * VGA_HEIGHT)
		{
			scroll_screen();
			cursor_pos = (VGA_HEIGHT - 1) * VGA_WIDTH;
		}
		move_cursor(cursor_pos);
		ksleep(delay);
	}
}

void
print_screen(const char *s, uint8_t attrib)
{
	print_dscreen(s, attrib, 0);
}

void
scroll_screen(void)
{
	volatile uint16_t *buffer = (uint16_t *)VGA_TEXT_BUFFER;

	for (int i = 0; i < (VGA_HEIGHT - 1) * VGA_WIDTH; i++)
	{
		buffer[i] = buffer[i + VGA_WIDTH];
	}

	for (int i = (VGA_HEIGHT - 1) * VGA_WIDTH; i < VGA_HEIGHT * VGA_WIDTH; i++)
	{
		buffer[i] = 0x0F00;
	}
}
