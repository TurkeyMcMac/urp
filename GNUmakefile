static = liburp.a
single-file = urp.c
mcu = atmega328p
flags = -mmcu=$(mcu) -std=gnu99 -Wall -Wextra -O3 $(CFLAGS)

sources = $(wildcard src/urp_*.c)
objects = $(patsubst src/%.c, build/%.o, $(sources))

$(static): $(objects)
	avr-ar crsu $@ $+

$(single-file): $(sources)
	./cat-sources $+ > $@

build/%.o: src/%.c urp.h
	avr-gcc $(flags) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(static) $(single-file) $(objects)
