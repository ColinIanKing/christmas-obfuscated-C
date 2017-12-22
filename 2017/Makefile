BINDIR=/usr/bin

all:
	gcc 3d.c -o 3d -lncursesw -lm

clean:
	rm 3d

install:
	mkdir -p ${DESTDIR}/${BINDIR}
	cp 3d ${DESTDIR}/${BINDIR}
