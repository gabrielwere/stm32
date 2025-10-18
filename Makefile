FILE = $(DIR)/main
C_SOURCES = startup.c $(FILE).c
C_OBJ = $(C_SOURCES:.c=.o)
INCLUDE = -Iinclude
CFLAGS = -mcpu=cortex-m3 -mthumb -nostdlib -std=gnu11 -Os -fdata-sections -ffunction-sections 
LDFLAGS = -mcpu=cortex-m3 -mthumb -nostdlib -Tlinker.ld -Wl,--gc-sections

$(FILE).hex : $(FILE).elf
	arm-none-eabi-objcopy -Oihex $^ $@

$(FILE).elf : $(C_OBJ)
	arm-none-eabi-gcc $(LDFLAGS) -o $@ $^

%.o : %.c
	arm-none-eabi-gcc $(CFLAGS) $(INCLUDE) -c $^ -o $@

upload:
	openocd -f interface/stlink.cfg -c "transport select hla_swd" -f target/stm32f1x.cfg -c "program {$(FILE).hex} verify reset; shutdown;"

clean:
	rm *.o $(DIR)/*.o $(DIR)/*.elf $(DIR)/*.hex
