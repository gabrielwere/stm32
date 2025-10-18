ENTRY(reset_handler)

MEMORY
{

	FLASH_ROM(rx):ORIGIN =0x08000000,LENGTH =64K
	SRAM(rwx):ORIGIN =0x20000000,LENGTH =20K

}

SECTIONS
{

	.isr_vector : 
	{
		KEEP(*(.isr_vector))
	}>FLASH_ROM

	.text : 
	{
		. = ALIGN(4);

		*(.text)
	    *(.text.*)
	    *(.init)
	    *(.fini)
	    *(.rodata)
	    *(.rodata.*)

    	. = ALIGN(4);
		_etext = .;

	}>FLASH_ROM

	 _la_data = LOADADDR(.data);

	.data : 
	{

		_sdata = .;
		*(.data)
		*(.data.*)

		. = ALIGN(4);
		_edata = .;

	}>SRAM AT>FLASH_ROM

	.bss : 
	{
		_sbss = .;
		*(.bss)
		*(.bss.*)
		*(COMMON)

		. = ALIGN(4);
		_ebss = .;
	}

}
