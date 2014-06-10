// Copyright 2014 Ngee Ann Polytechnic
// This is the client-side script

#ifndef _OTPAKEC_H
#define _OTPAKEC_H

#include <string>
#include "gmp.js/gmp.h"
#include "gmp.js/gmpxx.h"

using std::string;

class OtpakeC {
    private:
        mpz_class p;    // Prime
        mpz_class g;    // Generator
        mpz_class pv;   // Random (Private)
        mpz_class eC;   // Client Ephemeral
        mpz_class eS;   // Server Ephemeral
        mpz_class s;    // Shared Secret
        string cid;     // Client ID
        string sid;     // Server ID
        string otp;     // OTP
        string v;       // Verification
        string k;       // Shared Key
        string hash1 = "yolo";
        string hash2 = "swag";
        string hash3 = "4je5u5";
        string hash4 = "420blazeit";

    public:
        DH(string clientID, string serverID, string oneTimePassword);
        void genPrivate();
        void genEphermeral();
        void genSharedSecret(string serverEphermeral);
        bool verifyOtherEphermeral();
        void genVerification(string serverVerification);
        bool verifyOtherVerification(string serverVerification);
        void genSharedKey();

        string textToNum(string text);
        string hashSha256(string sStr);
        string cryptoXOR(string message, string nonce);

        string getPublicKey() {return puK.get_str();}
        string getPrivateKey() {return pvK.get_str();}
        string getSharedSecret() {return s.get_str();}
        string getSharedKey() {return k;}
};

#endif
