monitor reset halt
monitor load_image start.elf
monitor resume 0x20010344
monitor sleep 1
monitor halt
