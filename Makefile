all: test

test: test.o dh.o
	em++ test.o dh.o gmp.js/.libs/libgmp.a gmp.js/.libs/libgmpxx.a libsodium/libsodium-js/lib/libsodium.a -o test.js

test.o:
	em++ -c test.cc

dh.o:
	em++ -c dh.cc

clean:
	rm -rf *.o test.js
