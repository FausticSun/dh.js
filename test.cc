// Copyright 2014 FausticSun

#include <iostream>
#include <string>
#include "dh.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    DH dh1;
    DH dh2;
    cout << "dh1 Private Key: " << dh1.getPrivateKey() << endl
    << endl << "dh1 Public Key: " << dh1.getPublicKey() << endl
    << endl << "dh2 Private Key: " << dh2.getPrivateKey() << endl
    << endl << "dh2 Public Key: " << dh2.getPublicKey() << endl << endl;
    dh1.genSecret(dh2.getPublicKey());
    dh2.genSecret(dh1.getPublicKey());
    cout << "dh1 Secret: " << dh1.getSharedSecret() << endl
    << endl << "dh2 Secret: " << dh2.getSharedSecret() << endl << endl;
    if (dh1.getSharedSecret() == dh2.getSharedSecret()) {
        cout << "Exchange Success" << endl << endl;
    } else {
        cout << "Exchange Failure" << endl << endl;
    }
    dh1.genKey();
    dh2.genKey();
    if (dh1.getSharedKey() == dh2.getSharedKey()) {
        cout << "Key Success" << endl << endl;
    } else {
        cout << "Key Failure" << endl << endl;
    }
    cout << "Shared Key: " << dh1.getSharedKey() << endl << endl;
    string text = "Hello World!";
    string nonce = "abcdefghijklmnopqrstuvwx";
    string ciphertext = dh1.cryptoXOR(text, nonce);
    string unciphertext = dh1.cryptoXOR(ciphertext, nonce);
    cout << "Input: " << text << endl << endl;
    cout << "Encrypted: " << ciphertext << endl << endl;
    cout << "Decrypted: " << unciphertext << endl << endl;
}
