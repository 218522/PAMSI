#ifndef FILE_SERVICE_H
#define FILE_SERVICE_H
#include<iostream>
#include<string>

using namespace std;

class file_service
{
    public:
        void write_to_file(std::string text){
            fstream plik_1;
            plik_1.open("wyniki.txt", ios::out | ios::app);
            if(plik_1.good() == true)
            {
                plik_1 << text<<endl;
                plik_1.close();
            }
        }
};

#endif // FILE_SERVICE_H
