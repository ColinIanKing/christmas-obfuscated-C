#
#  Need to install ppmtojpeg to and run this
#	e.g. sudo apt-get install netpbm
#
BINDIR=/usr/bin

all:
	$(CC) koch-binary.c -lm -o koch-binary
	./koch-binary | ppmtojpeg > koch-binary.jpg

clean:
	rm -f koch-binary koch-binary.jpg

install:
	mkdir -p ${DESTDIR}/${BINDIR}
	cp koch-binary ${DESTDIR}/${BINDIR}
