all: test

test: test.o dh.o
	g++ test.o dh.o gmp.js/.libs/libgmp.a gmp.js/.libs/libgmpxx.a libsodium/src/libsodium/.libs/libsodium.a -o test.out

test.o:
	g++ -c test.cc

dh.o:
	g++ -c dh.cc

clean:
	rm -rf *.o test.out
