CC=@gcc
CFLAGS=-Wall -Werror -v -march=haswell -fomit-frame-pointer -O3 -pipe

OBJ=watch.o \
	dec_rand.o \
	dec_print.o \
	dec_ucmp.o \
	dec_cmp.o \
	dec_cpy.o \
	dec_iszero.o \
	dec_uadd.o \
	dec_add.o \
	dec_uadd2i.o \
	dec_usub.o \
	dec_sub.o \
	dec_umul.o \
	dec_mul.o \
	dec_imul.o \
	kara_combine.o \
	kara_sub.o \
	kara_add.o \
	kara_mul.o \
	kara.o \
	fast_kara_sub.o \
	fast_kara_mul.o \
	fast_kara.o \
	mandelbrot.o

TST=dec_uadd_commutative.o \
	dec_add_zero.o \
	dec_add_commutative.o \
	dec_sub_zero.o \
	dec_sub_commutative.o \
	dec_mul_zero.o \
	dec_mul_commutative.o \
	dec_uadd2i_equal.o \
	kara_mul_equal.o \
	kara_perf.o \
	test.o

%.o : src/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o : src/utils/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o : src/math/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o : src/math/kara/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o : src/math/frac/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o : test/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o : test/math/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

all: clean $(OBJ)
	ar rvs lib/libproip.a $(addprefix obj/, $(OBJ))

test: all $(TST)
	$(CC) $(CFLAGS) -o bin/test $(addprefix obj/, $(TST)) -Llib -lproip

clean:
	@mkdir -p bin obj lib
	@rm -rf bin/*
	@rm -rf obj/*
	@rm -rf lib/*
