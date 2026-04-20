/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kmain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:23:35 by mgama             #+#    #+#             */
/*   Updated: 2026/04/20 16:39:54 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

__attribute__((noreturn)) int
kmain()
{
	const char* msg = "Hello, Kernel World!\n";

	clear_screen(VGA_BACK_BLACK);
	print_screen(msg, VGA_FORE_WHITE | VGA_BACK_BLACK);

	// Keeping kernel alive!
	while (1)
	{
		__asm__ volatile ("hlt");
	}
}
