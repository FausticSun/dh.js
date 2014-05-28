// Copyright 2014 FausticSun

#include <iostream>
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
        cout << "Exchange Success" << endl;
    } else {
        cout << "Exchange Failure" << endl;
    }
}
