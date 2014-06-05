// Copyright 2014 FausticSun

#include <iostream>
#include "libsodium/src/libsodium/include/sodium.h"
#include "dh.h"

DH::DH() {
    p = "0xFFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3DC2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F83655D23DCA3AD961C62F356208552BB9ED529077096966D670C354E4ABC9804F1746C08CA18217C32905E462E36CE3BE39E772C180E86039B2783A2EC07A28FB5C55DF06F4C52C9DE2BCBF6955817183995497CEA956AE515D2261898FA051015728E5A8AACAA68FFFFFFFFFFFFFFFF";
    g = 2;
    genPrivateKey();
    genPublicKey();
}

void DH::genPrivateKey() {
    // Currently using libsodium randombytes for testing
    // To be replaced with window.crypto.getRandomValues
    gmp_randclass rng(gmp_randinit_default);
    rng.seed(randombytes_uniform(100));
    pvK = rng.get_z_bits(1030);
}

void DH::genPublicKey() {
    mpz_powm(puK.get_mpz_t(), g.get_mpz_t(), pvK.get_mpz_t(), p.get_mpz_t());
}

void DH::genSecret(string otherKey) {
    mpz_class oK;
    oK = otherKey;
    mpz_powm(s.get_mpz_t(), oK.get_mpz_t(), pvK.get_mpz_t(), p.get_mpz_t());
}

void DH::genKey() {
    string sStr = s.get_str();
    unsigned char h[crypto_hash_sha256_BYTES];
    crypto_hash_sha256(h,(const unsigned char *) sStr.c_str(),sStr.size());
    k = string((char *) h,sizeof h);
}

string DH::cryptoXOR(string m, string n) {
    if (n.size() != crypto_stream_NONCEBYTES) throw "incorrect nonce length";
    if (k.size() != crypto_stream_KEYBYTES) throw "incorrect key length";
    size_t mlen = m.size();
    unsigned char c[mlen];
    crypto_stream_xor(c,
                      (const unsigned char *) m.c_str(),mlen,
                      (const unsigned char *) n.c_str(),
                      (const unsigned char *) k.c_str()
                      );
    return string((char *) c,mlen);
}