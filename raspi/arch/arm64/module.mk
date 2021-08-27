SRCFILES += arch/arm64/mini_uart.c

ASMFILES += arch/arm64/boot.S \
	    arch/arm64/mm.S \
	    arch/arm64/utils.S \
	    arch/arm64/exception.S

HDRFILES += $(SRCFILES:.c=.h) \
	arch/arm64/peripherals/base.h \
	arch/arm64/peripherals/gpio.h \
	arch/arm64/peripherals/mini_uart.h \
	arch/arm64/peripherals/irq.h \
	arch/arm64/peripherals/timer.h \
	arch/arm64/arm/sysregs.h

AUXFILES +=
