CC=@gcc
CFLAGS=-v -march=haswell -fomit-frame-pointer -O2 -pipe

HEAD=defs.h math/dec.h
OBJ=dec_print.o dec_cmp.o dec_add.o dec_radd.o dec_rsub.o dec_rand.o watch.o
TEST=main.o dec_radd_commutative.o dec_add_commutative.o

%.o:src/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o:src/math/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o:src/utils/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o:test/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o:test/math/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%h:
	cp src/$@ include/

all: clean $(OBJ) $(HEAD)
	ar rvs lib/libproip.a $(addprefix obj/, $(OBJ))

test: all $(TEST)
	$(CC) $(CFLAGS) -o bin/test $(addprefix obj/, $(TEST)) -Llib -lproip

clean:
	@mkdir -p bin obj lib include
	@rm -rf include/*
	@rm -rf bin/*
	@rm -rf obj/*
	@rm -rf lib/*
