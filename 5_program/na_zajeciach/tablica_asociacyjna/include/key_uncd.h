#ifndef KEY_UNCD_H
#define KEY_UNCD_H
#include <string>
#include<iostream>
using namespace std;
class key_uncd
{
    public:
        int operator[] (string key){
        cout<<"My name is "<<key<<endl;
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!";
        const char* alphabet_by_letter = alphabet.c_str();
        const char* key_by_letter = key.c_str();
        int i;
        for(i=0;(alphabet_by_letter[i]==key_by_letter[i])&&i<(alphabet.size());i++){}
        if(i==26){
            cout<<"Name error, cant read first letter"<<endl;
            i=-1;
        }
        cout<<"xx "<<i<<endl;
        return i;
        }
};

#endif // KEY_UNCD_H
