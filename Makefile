all: broken.a

broken.a: broken.c broken.h
	clang -c -o broken.o broken.c
	ar -r broken.a broken.o broken.h

clean:
	rm -f *.a *.o
