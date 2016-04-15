#include <iostream>
#include <string>
#include <key_uncd.h>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    key_uncd decoder;
    string Name = "Kowalski";
    int decoded = decoder[Name];
    cout<<decoded;
    return 0;
}
