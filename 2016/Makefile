BINDIR=/usr/bin

all:
	gcc snow.c -o snow -lncursesw

clean:
	rm snow

install:
	mkdir -p ${DESTDIR}/${BINDIR}
	cp snow ${DESTDIR}/${BINDIR}
