.PHONY: all
all: build/battle_of_revolution

.PHONY: clean
clean:
	rm -rf build objects
.PHONY: run 
run:
	./build/battle_of_revolution

build/libsys.so: libsys.c
	gcc -c -g -fPIC libsys.c -o objects/libsys.o
	gcc -shared objects/libsys.o -o build/libsys.so
build/libgame.so: libgame.c
	gcc -c -g -fPIC libgame.c -o objects/libgame.o
	gcc -shared objects/libgame.o -o build/libgame.so
build/core: core.c build/libsys.so build/libgame.so
	gcc -c -g core.c -o objects/core.o
	gcc objects/core.o -L build -lgame -lsys -o build/core

build/battle_of_revolution: folder build/libsys.so build/core
	gcc -g battle_of_revolution.c -o build/battle_of_revolution
folder:
	mkdir -p build objects
