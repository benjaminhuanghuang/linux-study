qemu-system-x86_64 -kernel ~/workspace/linux/arch/x86/boot/bzImage \
  -hda ~/workspace/rootfs/rootfs.img \
  -append "root=/dev/sda console=ttyS0" \
  -nographic \
  nokaslr -s