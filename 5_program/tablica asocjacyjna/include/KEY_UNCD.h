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
            string alphabet = "abcdefghijklmnopqrstuvwxyz!";
            const char* alphabet_by_letter = alphabet.c_str();
            const char* key_by_letter = key.c_str();
            int i;
            for(i=0;(alphabet_by_letter[i]!=key_by_letter[0])&&i<(alphabet.size()-1);i++){}
                if(i==26){
                    cout<<"Name error, cant read first letter"<<endl;
                    cout<<"Can read only big letters"<<endl;
                    i=-1;
                }
            return i;
            }
};

#endif // KEY_UNCD_H
