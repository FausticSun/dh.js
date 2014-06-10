all: test

test: test.o dh.o
	em++ test.o dh.o gmp.js/.libs/libgmp.a gmp.js/.libs/libgmpxx.a libsodium/libsodium-js/lib/libsodium.a -o test.js

test.o:
	em++ -c test.cc

dh.o:
	em++ -c dh.cc

something: something.o
	em++ something.o gmp.js/.libs/libgmp.a gmp.js/.libs/libgmpxx.a libsodium/libsodium-js/lib/libsodium.a -o something.js

something.o:
	em++ -c something.cc

clean:
	rm -rf *.o test.js something.js
