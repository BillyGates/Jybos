#!/bin/bash
if [ $1 = "bochs" ]; then
    if [ $2 = "floppy" ]; then
    # bochs-floppy
    bochs -q -f scripts/bochs_floppy.bxrc
    fi
    if [ $2 = "cdrom" ]; then
    # bochs-cdrom
    bochs -q -f scripts/bochs_cdrom.bxrc
    fi
fi
if [ $1 = "qemu" ]; then
    if [ $2 = "floppy" ]; then
    # qemu-floppy
    qemu -m 512 -fda floppy.img
    fi
    if [ $2 = "cdrom" ]; then
    # qemu-cdrom
    qemu -m 512 -cdrom cdrom.iso
    fi
fi
