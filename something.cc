#include <iostream>
#include <string>
#include <bitset>
#include "gmp.js/gmp.h"
#include "gmp.js/gmpxx.h"
#include "libsodium/libsodium-js/include/sodium/crypto_hash_sha256.h"
#include <emscripten.h>

using namespace std;

string textToNum(string text) {
    string tmp = "";
    for (int i = 0; i < text.size(); ++i) {
        tmp.append(bitset<8>(text[i]).to_string());
    }
    mpz_class num(tmp, 2);
    return num.get_str();
}

string hashSha256(string sStr) {
    unsigned char h[crypto_hash_sha256_BYTES];
    crypto_hash_sha256(h, (const unsigned char *) sStr.c_str(), sStr.size());
    return string(reinterpret_cast<char*>(h), sizeof h);
}

string genEphermeral(string cid, string sid, string otp) {
	mpz_class p;
	p = "0xFFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3DC2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F83655D23DCA3AD961C62F356208552BB9ED529077096966D670C354E4ABC9804F1746C08CA18217C32905E462E36CE3BE39E772C180E86039B2783A2EC07A28FB5C55DF06F4C52C9DE2BCBF6955817183995497CEA956AE515D2261898FA051015728E5A8AACAA68FFFFFFFFFFFFFFFF";
	mpz_class g;
	g = 2;
	gmp_randclass rng(gmp_randinit_default);
    int seed = EM_ASM_INT({
        return Math.floor((Math.random() * $0) + 1);
    }, 100);
    rng.seed(seed);
    mpz_class pv = rng.get_z_bits(1030);

    mpz_class pub;
    mpz_class hashpow;
    mpz_class e;
    mpz_class hashnum(textToNum(hashSha256(cid+sid+otp)));
    mpz_powm(pub.get_mpz_t(), g.get_mpz_t(), pv.get_mpz_t(), p.get_mpz_t());
    mpz_pow_ui(hashpow.get_mpz_t(), hashnum.get_mpz_t(), 2);
    mpz_mul(e.get_mpz_t(), pub.get_mpz_t(), hashpow.get_mpz_t());
    return e.get_str();
}

//bool verifyOtherVerification(string serverVerification) {
//    return serverVerification == hashSha256(cid+sid+eC+eS+s+otp+hash2) ? true : false;
//}

int main() {
	string test1 = "test";
	string test2 = "test";
	cout << (test1==test2?"true":"false") << endl;
}
