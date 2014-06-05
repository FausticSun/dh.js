// Copyright 2014 FausticSun

#ifndef _DH_H
#define _DH_H

#include <string>
#include "gmp.js/gmp.h"
#include "gmp.js/gmpxx.h"

using std::string;

class DH {
    private:
        mpz_class p, g, pvK, puK, s; //Prime, Gen, Public, Private, Shared Secret
        string k;  // Shared Key

    public:
        DH();
        void genPrivateKey();
        void genPublicKey();
        void genSecret(string otherKey);
        void genKey();
        string cryptoXOR(string message, string nonce);

        string getPrime() {return p.get_str();}
        string getGenerator() {return g.get_str();}
        string getPublicKey() {return puK.get_str();}
        string getPrivateKey() {return pvK.get_str();}
        string getSharedSecret() {return s.get_str();}
        string getSharedKey() {return k;}
};

#endif
