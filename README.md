dh.js
=====

Diffie-Hellman implementation in C++ compiled to JavaScript using Emscripten

As with any JavaScript crypto stuff, this probably shoudn't be used seriously on the web


Building
========

1. Follow instructions on gmp.js and compile it (note that it only compiles on 32-bit systems)
2. Download libsodium tarball, extract the contents of the libsodium-x.x.x folder to libsodium and compile that
3. Run make