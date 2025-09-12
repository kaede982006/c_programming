.PHONY: all
all: structure_alignment

.PHONY: clean
clean:
	rm -f *.o structure_alignment
%.o: %.c
	gcc $< -c -o $@
structure_alignment: main.o structures.o
	gcc $^ -o $@


