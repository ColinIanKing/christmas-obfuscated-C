#
#  Guru Meditation numbers
#
M1=0x52,0x49,0x46,0x46,0x24,0,160,40,0x57,0x41,0x56,
M2=0x45,0x66,0x6d,0x74,32,16,0,0,0,1,0,1,0,0x44,0xac,
M3=0,0,0x88,0x48,1,0,2,0,16,0,0x64,0x61,0x74,0x61,0,
M4=0,0xa0,40,0,0,0,0

ifeq (, $(shell which aplay))
$(error "Tool aplay not found, please install it")
endif

wavy: wavy.c
	@echo $(CC) $^ -Os -o $@ -lm
	@$(CC) $^ -DG=return -Dg=typedef -DJ=for -DY=$(M1)$(M2)$(M3)$(M4) -Os -o $@ -lm

music: wavy
	./wavy | aplay

clean:
	rm -f wavy

install:
	mkdir -p ${DESTDIR}/${BINDIR}
	cp wavy ${DESTDIR}/${BINDIR}
