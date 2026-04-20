/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kmain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:23:35 by mgama             #+#    #+#             */
/*   Updated: 2026/04/20 18:25:02 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"
#include "delay.h"

void
print_logo()
{
	print_screen("\n\n\n\n\n\n\n\n", VGA_FORE_CYAN | VGA_BACK_BLACK);

    const char* logo =
    "                           ____       _ _ _             \n"
    "                          / ___|__ __| (_) | ___  ___   \n"
    "                         | |  _/ _`  | | | |/ _ \\/ _ \\  \n"
    "                         | |_| | (_| | | | |  __/ (_) | \n"
    "                          \\____|\\__,_|_|_|_|\\___|\\___/  \n"
    "                                                       \n"
    "                                Kernel Project           ";

    print_screen(logo, VGA_FORE_CYAN | VGA_BACK_BLACK);
}

int
kmain()
{
	init_screen();

	ksleep(500);

	disable_cursor();
	clear_screen();
	print_logo();

	ksleep(1000);
	clear_screen();
	enable_cursor(14, 15);
	
	const char* msg = "Hello, Kernel World!\n\nThis is my simple kernel, for the KFS 42 school project.\n";

	ksleep(500);
	print_dscreen(msg, VGA_FORE_WHITE | VGA_BACK_BLACK, 10);

	ksleep(3000);
	clear_screen();

	print_dscreen("42", VGA_FORE_WHITE | VGA_BACK_BLACK, 10);

	return (0);
}
