ENTRY(_start)
SECTIONS {
    . = 1M; /* Le noyau est chargé à 1Mo */
    .text : {
        *(.multiboot) /* On s'assure que le header Multiboot est en premier */
        *(.text)
    }
    .data : { *(.data) }
    .bss  : { *(.bss)  }
}