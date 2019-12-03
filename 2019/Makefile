snowman2019: snowman.c
	gcc $^ -O2 -o $@ 
	strip $@

clean:
	rm -f snowman2019

install:
	mkdir -p ${DESTDIR}/${BINDIR}
	cp snowman2019 ${DESTDIR}/${BINDIR}
