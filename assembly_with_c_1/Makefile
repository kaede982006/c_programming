.PHONY: all
all: main

.PHONY: clean
clean:
	rm -f *.o main

asmio.o: asmio.asm
	nasm -f elf64 -o $@ $<

main.o: main.c
	gcc -c -o $@ $<

main: main.o asmio.o
	gcc $^ -o $@
