## Linux Boot Process

1. Firmware stage: execute code in BIOS of UEFI, starts boot loader

2. Bootloader stage, GRUB2(grand unifiled boot loader)
   config on BIOS machine: /boot/grub2/grub.cfg
   config on UEFI machine: /boot/efi/EFI/redhat/grub.efi

3. kernel Stage: load ramdisk into ram, load device driver and config files from ramdisk, mounts root filesystem

4. Initialization Stage: start grandfather process(systemd), systemd start system service and login shell & GUI
