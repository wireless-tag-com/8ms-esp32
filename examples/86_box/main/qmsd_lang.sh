python nvs_partition_gen.py generate qmsd_lang.csv qmsd_lang.bin 0x8000 --version 2
esptool.py --chip esp32 -p /dev/tty.usbserial-022118A9 -b 460800 --before=default_reset --after=hard_reset write_flash --flash_mode dio --flash_freq 40m --flash_size 4MB 0x20000 qmsd_lang.bin
