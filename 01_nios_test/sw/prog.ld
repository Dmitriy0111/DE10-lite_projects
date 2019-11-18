MEMORY
{
    ram( rwx ) : ORIGIN = 0x00000000, LENGTH = 16384
}

SECTIONS
{
    .text : { *(.text*) } > ram
}