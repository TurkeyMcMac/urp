# urp

urp is a library for Unified Readable Pointers on AVR microcontrollers. This
means that the same code can read memory from either RAM or flash (program
memory.) This is to avoid situations like the standard library needing both
`strlen` and `strlen_P`.

## Design

For API information, see `urp.h`.

A `URPTR` is a `char*` to either RAM or flash. A `URPTR` is a 16-bit integer.
The highest bit is 0 if the pointer is for RAM and 1 if it is for flash. The
design is very simple. The functions provided in the library are mostly for
convenience. For size- or performance-intensive purposes, one might have to
reimplement some functionality.

## Examples

See `src/*.c`, especially the files implementing functions marked `NOT TRIVIAL`
in `urp.h`, such as `urp_strspn`.

## Caveats

I don't know if this is actually useful because I have not used it for anything
other than implementing the functions in the library.

Only the bottom 32KiB of flash or RAM can be addressed. This is not an issue on
microcontrollers such as the ATmega328 which don't have more memory than that.

At the moment, string functions taking two or more URPTR arguments are
implemented manually without much care for speed.
