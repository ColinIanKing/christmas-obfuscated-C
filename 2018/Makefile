
happy-christmas: happy-christmas.c
	gcc $^ -o $@
	strip $@

message: happy-christmas
	./$^ < happy-christmas.c > $^.wav || true

clean:
	rm -f happy-christmas happy-christmas.wav

install:
	mkdir -p ${DESTDIR}/${BINDIR}
	cp happy-christmas ${DESTDIR}/${BINDIR}
