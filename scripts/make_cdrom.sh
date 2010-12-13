#!/bin/bash
# Temponären Ordner erstellen.
mkdir -p cdrom/boot/grub
mkdir -p cdrom/system
# Den NandOS-Kernel auf das Image kopieren.
cp src/kernel/kernel cdrom/system/kernel
# Eltorito Stage 2 von GRUB auf das Image kopieren.
cp scripts/grub/stage2_eltorito cdrom/boot/grub/stage2_eltorito
# Den Splash Screen auf das Image kopieren.
cp scripts/grub/splash.xpm.gz cdrom/boot/grub/splash.xpm.gz
# Die menu.lst auf das Image kopieren.
cp scripts/grub/cdrom_menu.lst cdrom/boot/grub/menu.lst
# ISO Dtei erstellen.
mkisofs -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o cdrom.iso cdrom/
# Temponären Ordner löschen.
rm -r cdrom/
