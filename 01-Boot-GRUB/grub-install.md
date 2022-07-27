grub-core/osdep/basic/init.c

util/setup.c
grub_util_bios_setup 函数从磁盘读取 boot.img 和 core.img，设置根设备，复制分区表（稍后会看到更多），读取分区表，检查错误并写入 core.img 和 boot.img：

```
for (i = 0; i < nsec; i++)
	grub_disk_write (dest_dev->disk, sectors[i], 0,
		             GRUB_DISK_SECTOR_SIZE,
		             core_img + i * GRUB_DISK_SECTOR_SIZE);
...
...
...
if (grub_disk_write (dest_dev->disk, BOOT_SECTOR,
                     0, GRUB_DISK_SECTOR_SIZE, boot_img))
    grub_util_error ("%s", grub_errmsg);
```
