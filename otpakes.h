// Copyright 2014 Ngee Ann Polytechnic
// This is the server-side script

#ifndef _OTPAKES_H
#define _OTPAKES_H

#include <string>
#include "gmp.js/gmp.h"
#include "gmp.js/gmpxx.h"

using std::string;

class OtpakeS {
    private:
        mpz_class p;    // Prime
        mpz_class g;    // Generator
        mpz_class pv;   // Random (Private)
        mpz_class eC;   // Client Ephemeral
        mpz_class eP;   // Server Ephemeral
        mpz_class s;    // Shared Secret
        string cID;     // Client ID
        string sID;     // Server ID
        string otp;     // OTP
        string v;       // Verification
        string k;       // Shared Key

    public:
        DH(string clientID, string serverID, string clientEphemeral);
        void genPrivate();
        void genEphermeral();
        void genSharedSecret();
        bool verifyOtherEphermeral();
        void genVerification();
        bool verifyOtherVerification(string clientVerification);
        void genSharedKey();

        string cryptoXOR(string message, string nonce);

        string getPublicKey() {return puK.get_str();}
        string getPrivateKey() {return pvK.get_str();}
        string getSharedSecret() {return s.get_str();}
        string getSharedKey() {return k;}
};

#endif
