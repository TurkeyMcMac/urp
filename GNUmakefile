static = liburp.a
single-file = urp.c
mcu = atmega328p
flags = -mmcu=$(mcu) -std=gnu89 -Wall -Wextra -O3 $(CFLAGS)

sources = $(wildcard src/urp_*.c)
objects = $(patsubst src/%.c, build/%.o, $(sources))

.PHONY: all
all: $(static) $(single-file)

$(static): $(objects)
	avr-ar crsu $@ $+

$(single-file): $(sources)
	./cat-sources `printf '%s\n' $+ | sort` > $@

build/%.o: src/%.c urp.h
	avr-gcc $(flags) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(static) $(single-file) $(objects)
