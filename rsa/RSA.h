#include <iostream>
#include <list>
#include <algorithm>
#include "Keys.h"
#include <string>
#define MAX_SIZE_ARRAY 128
using namespace std;
class RSA
{
    public:
    Keys KeyGenerator()
    {
        int app;
        int Q, P;
        int N, Z;
        int E;
        int D;
        int K;
        cout<<"CIN Q"<<endl;
        cin>>Q;
        cout<<"CIN P"<<endl;
        cin>>P;
        cout<<"genera N"<<endl;
        N = generateN(P, Q);
        cout<<"N "<< N<<endl;
        cout<<"genera Z"<<endl;
        Z = generateZ(P, Q);
        cout<<"Z "<< Z<<endl;
        cout<<"genera E"<<endl;
        E = generateE(Z);
        cout<<"E "<< E<<endl;
        cout<<"genera D"<<endl;
        D = generateD(E, Z);
        cout<<"D "<< D<<endl;
        Keys key;
        key.setKey_N(N);
        key.setPrivateKey_D(D);
        key.setPublicKey_E(E);
        return key;
    }
    int getMaxSize()
    {
        return MAX_SIZE_ARRAY;
    }
     char* cripta(char charArray[MAX_SIZE_ARRAY], Keys key)
     {
            double arrayINT[MAX_SIZE_ARRAY];
            for(int i = 0; i<MAX_SIZE_ARRAY;i++)
            {
                arrayINT[i] = (int)charArray[i];
            }
            for(int i = 0; i<MAX_SIZE_ARRAY;i++)
            {
                cout<<arrayINT[i]<<"  ";
            }
            cout<<endl;
            int msg[MAX_SIZE_ARRAY];
            for(int i = 0; i<MAX_SIZE_ARRAY;i++)
            {
                double INTE = pow(arrayINT[i], key.getPublicKey_E());
                cout<<"Int^E  "<<INTE<<" ";
                msg[i]=fmod(pow(arrayINT[i], key.getPublicKey_E()), key.getDoubleKey_N());
                cout<<msg[i]<<"  "<<endl;
            }
            char result[MAX_SIZE_ARRAY];
            cout<<endl;
            for(int i = 0; i<MAX_SIZE_ARRAY;i++)
            {
                cout<<(char)msg[i];
            }
            for(int i = 0; i<MAX_SIZE_ARRAY;i++)
            {
                result[i] = (char)msg[i];
            }
            return result;
        }
    private:
        int generateN(int p, int q)
        {
            return p*q;
        }
        int generateZ(int p, int q)
        {
            return (p-1)*(q-1);
        }
        int generateE(int z){
            list<int> factorZ = factor(z);
            list<int> factorI;
            bool resto = true;
            int cont = 3;
            while(resto)
            {
                bool dest = true;
                factorI = factor(cont);
                cout<<"Count == "<<cont<<endl;
                list<int>::iterator it;
                for(list<int>::iterator iter = factorI.begin(); iter != factorI.end(); iter++ )
                {
                        int value = *iter;
                        it = find(factorZ.begin(), factorZ.end(), value);
                        if(it!=factorZ.end())
                        {
                            dest = false;
                            break;
                        }
                }
                if(dest)return cont;
                cont+=2;
            }
       }
       list<int> factor(int z)
       {
            list<int> fattori;
            int app;
            app = z;
            cout<<"start to working on factorization"<<endl;
            while(app!=1)
            {
                for(int i=2;i<=z;i++)
                {
                    if(app%i==0)
                    {
                        app = app/i;
                        fattori.push_back(i);
                        break;
                    }
                }
            }
            fattori.sort();
            fattori.unique();
            return fattori;
        }
        int generateD(int e , int z)
        {
            int i = 1;
            while((i*z+1)%e!=0)
            {
                i++;
            }
            cout<<"K = "<<i;
            cout<<"D = "<<((i*z)+1)/e;
            return ((i*z)+1)/e;
        }
};
