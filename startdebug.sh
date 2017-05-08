#/bin/sh

arm-none-eabi-gdb -eval-command "target remote localhost:3333" Debug/FirstProject.elf
