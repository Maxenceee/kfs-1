/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:26:25 by mgama             #+#    #+#             */
/*   Updated: 2026/04/20 16:39:37 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
#define PRINT_H

#include <types.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

#define VGA_TEXT_BUFFER 0xb8000u

#define VGA_FORE_BLACK			0x0
#define VGA_FORE_BLUE			0x1
#define VGA_FORE_GREEN			0x2
#define VGA_FORE_CYAN			0x3
#define VGA_FORE_RED			0x4
#define VGA_FORE_MAGENTA		0x5
#define VGA_FORE_BROWN			0x6
#define VGA_FORE_LIGHT_GREY		0x7
#define VGA_FORE_DARK_GREY		0x8
#define VGA_FORE_LIGHT_BLUE		0x9
#define VGA_FORE_LIGHT_GREEN	0xA
#define VGA_FORE_LIGHT_CYAN		0xB
#define VGA_FORE_LIGHT_RED		0xC
#define VGA_FORE_LIGHT_MAGENTA	0xD
#define VGA_FORE_LIGHT_BROWN	0xE
#define VGA_FORE_WHITE			0xF

#define VGA_BACK_BLACK			(VGA_FORE_BLACK << 4)
#define VGA_BACK_BLUE			(VGA_FORE_BLUE << 4)
#define VGA_BACK_GREEN			(VGA_FORE_GREEN << 4)
#define VGA_BACK_CYAN			(VGA_FORE_CYAN << 4)
#define VGA_BACK_RED			(VGA_FORE_RED << 4)
#define VGA_BACK_MAGENTA		(VGA_FORE_MAGENTA << 4)
#define VGA_BACK_BROWN			(VGA_FORE_BROWN << 4)
#define VGA_BACK_LIGHT_GREY		(VGA_FORE_LIGHT_GREY << 4)
#define VGA_BACK_DARK_GREY		(VGA_FORE_DARK_GREY << 4)
#define VGA_BACK_LIGHT_BLUE		(VGA_FORE_LIGHT_BLUE << 4)
#define VGA_BACK_LIGHT_GREEN	(VGA_FORE_LIGHT_GREEN << 4)
#define VGA_BACK_LIGHT_CYAN		(VGA_FORE_LIGHT_CYAN << 4)
#define VGA_BACK_LIGHT_RED		(VGA_FORE_LIGHT_RED << 4)
#define VGA_BACK_LIGHT_MAGENTA	(VGA_FORE_LIGHT_MAGENTA << 4)
#define VGA_BACK_LIGHT_BROWN	(VGA_FORE_LIGHT_BROWN << 4)
#define VGA_BACK_WHITE			(VGA_FORE_WHITE << 4)

void	print_screen(const char *s, uint8_t attrib);
void	clear_screen(uint8_t attrib);

#endif /* PRINT_H */