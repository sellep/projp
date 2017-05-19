CC=@gcc
CFLAGS=-v -march=haswell -fomit-frame-pointer -O2 -pipe

OBJ=main.o dec_print.o dec_cmp.o

%.o:src/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o:src/math/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

all: clean $(OBJ)
	$(CC) $(CFLAGS) -o bin/main $(addprefix obj/, $(OBJ))

clean:
	@mkdir -p bin obj lib
	@rm -rf bin/*
	@rm -rf obj/*
	@rm -rf lib/*
