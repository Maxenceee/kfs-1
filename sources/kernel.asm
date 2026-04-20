; kernel.asm
section .multiboot
    align 4
    dd 0x1BADB002              ; Magic number pour Multiboot
    dd 0x00                    ; Flags
    dd -(0x1BADB002 + 0x00)    ; Checksum

extern printk

section .text
global _start

_start:
	mov ax, 0x10
	mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

	mov edi, msg              ; Adresse du message à afficher
	mov esi, 0                ; Longueur du message (0 pour les chaînes null-terminées)
	mov ax, 0x0F00            ; Attribut de couleur (blanc sur noir)
	printk

hang:
    hlt                     ; Arrête le processeur
    jmp hang

section .data
    msg db "Hello de GRUB en 32-bits!", 0
