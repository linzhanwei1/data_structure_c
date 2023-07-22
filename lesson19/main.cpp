#include "StaticArray.h"
#include <iostream>

using namespace std;
using namespace DTLib;

int main(int argc, char *argv[]) {
    StaticArray<int, 5> s1;

    for (int i = 0; i < s1.length(); i++) {
        s1[ i ] = i * i;
    }
    for (int i = 0; i < s1.length(); i++) {
        cout << s1[ i ] << endl;
    }

    cout << "============================" << endl;

    StaticArray<int, 5> s2;
    s2 = s1;

    for (int i = 0; i < s2.length(); i++) {
        cout << s2[ i ] << endl;
    }

    s2[ 5 ] = 100;

    return 0;
}
