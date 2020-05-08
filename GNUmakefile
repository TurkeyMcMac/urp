static = liburp.a
single-file = urp.c
tests = tests.hex
mcu = atmega328p
flags = -mmcu=$(mcu) -std=gnu99 -Wall -Wextra -Os $(CFLAGS)
# Test upload parameters:
programmer = arduino
partno = m328p
port = /dev/ttyUSB0

sources = $(wildcard src/urp_*.c)
objects = $(patsubst src/%.c, build/%.o, $(sources))

.PHONY: all
all: $(static) $(single-file) $(tests)

$(static): $(objects)
	avr-ar crsu $@ $+

$(single-file): $(sources)
	./cat-sources `printf '%s\n' $+ | sort` > $@

$(tests): tests.c $(static) urp.h
	avr-gcc $(flags) -o $@ $< $(static)
	avr-objcopy -O ihex $@
	chmod -x $@

.PHONY: upload-tests
upload-tests: $(tests)
	avrdude -c$(programmer) -p$(partno) -P$(port) -Uflash:w:$<:i

build/%.o: src/%.c urp.h
	avr-gcc $(flags) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(static) $(objects) $(tests)
