#
#  Need to install ppmtojpeg to and run this
#	e.g. sudo apt-get install netpbm
#

all:
	$(CC) koch-binary.c -lm -o koch-binary
	./koch-binary | ppmtojpeg > koch-binary.jpg

clean:
	rm -f koch-binary koch-binary.jpg
