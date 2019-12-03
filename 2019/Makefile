snowman: snowman.c
	gcc $^ -O2 -o $@ 
	strip $@

clean:
	rm -f snowman 

install:
	mkdir -p ${DESTDIR}/${BINDIR}
	cp snowman ${DESTDIR}/${BINDIR}
