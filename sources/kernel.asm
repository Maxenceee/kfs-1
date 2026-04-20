; kernel.asm
section .multiboot
	align 4
	dd 0x1BADB002              ; Magic number pour Multiboot
	dd 0x00                    ; Flags
	dd -(0x1BADB002 + 0x00)    ; Checksum

extern kmain

section .text
global _start

_start:
	mov esp, stack_space	; Initialisation de la pile

	; Call Kernel main function
	call kmain

section .bss
resb 8192                   ; Réserve 8 Ko pour la pile
stack_space: