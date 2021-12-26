#include <iostream>

using namespace std;

int main() {
    char ch;
    cout<<"Enter a character in uppercase: ";
    cin>> ch;

    ch+=32;
    cout <<"Entered character in lowercase: "<<ch;
    return 0;
}