SRCFILES += kernel/irq.c \
            kernel/printk.c \
	    kernel/timer.c

HDRFILES += $(SRCFILES:.c=.h)

AUXFILES +=
