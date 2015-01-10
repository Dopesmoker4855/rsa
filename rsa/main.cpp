#include <iostream>
#include <cmath>
#include "RSA.h"
using namespace std;


int main()
{
    RSA rsa;
    Keys key = rsa.KeyGenerator();
    cout<<"Private"<<endl;
    cout<<"( "<<key.getKey_N()<<" , "<<key.getPrivateKey_D()<<" )"<<endl;
    cout<<"Public"<<endl;
    cout<<"( "<<key.getKey_N()<<" , "<<key.getPublicKey_E()<<" )"<<endl;
    char arrayChar[rsa.getMaxSize()];
    cout<<"scrivi una stringa"<<endl;
    cin>>arrayChar;
    char msg[rsa.getMaxSize()];
    char *punt;
    punt = rsa.cripta(arrayChar, key);
    for(int i = 0; i<rsa.getMaxSize(); i++)
        msg[i] = punt[i];
}
