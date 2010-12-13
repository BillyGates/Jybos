#!/bin/bash

if ! [ -f floppy.img ]; then
    # Leeres Image erstellen und formatieren.
    dd if=/dev/zero of=floppy.img bs=1024 count=1440
    # Image formatieren.
    mkfs.msdos -n NandOS floppy.img
    # Image einhängen.
    mkdir -p floppy/
    sudo mount -o loop floppy.img floppy/
    # Grub Ordner erstellen.
    sudo mkdir -p floppy/boot/grub/
    # Stage 1 von GRUB auf das Image kopieren.
    sudo cp scripts/grub/stage1 floppy/boot/grub/stage1
    # Stage 2 von GRUB auf das Image kopieren.
    sudo cp scripts/grub/stage2 floppy/boot/grub/stage2
    # Den Splash Screen auf das Image kopieren.
    sudo cp scripts/grub/splash.xpm.gz floppy/boot/grub/splash.xpm.gz
    # Die menu.lst auf das Image kopieren.
    sudo cp scripts/grub/floppy_menu.lst floppy/boot/grub/menu.lst
    #Den System Ordner erstellen
    sudo mkdir floppy/system
    # Image aushängen.
    sleep
    sudo umount floppy/
    rmdir floppy/
    # GRUB installieren.
    grub --batch <<EOF
device (fd0) floppy.img
root (fd0)
setup (fd0)
EOF
fi

# Image einhängen.
mkdir -p floppy/
sudo mount -o loop floppy.img floppy/
# Den NandOS-Kernel auf das Image kopieren.
sudo cp src/kernel/kernel floppy/system/kernel
# einen Moment warten
sleep 1
# Image aushängen.
sudo umount floppy/
rmdir floppy/
