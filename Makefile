all:
	@$(MAKE) -C src --no-print-directory

clean:
	@$(MAKE) -C src clean --no-print-directory

image-floppy: all
	scripts/make_floppy.sh

bochs-floppy: image-floppy
	@scripts/run.sh bochs floppy

qemu-floppy: image-floppy
	@scripts/run.sh qemu floppy

image-cdrom:
	scripts/make_cdrom.sh

bochs-cdrom: image-cdrom
	@scripts/run.sh bochs cdrom

qemu-cdrom: image-cdrom
	@scripts/run.sh qemu cdrom

.PHONY: all clean image-floppy bochs-floppy qemu-floppy bochs-floppy qemu-floppy bochs-cdrom qemu-cdrom
