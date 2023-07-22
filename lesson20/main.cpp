#include "DynamicArray.h"
#include <iostream>

using namespace std;
using namespace DTLib;

int main(int argc, char *argv[]) {
    DynamicArray<int> s1(5);

    for (int i = 0; i < s1.length(); i++) {
        s1[ i ] = i * i;
    }
    for (int i = 0; i < s1.length(); i++) {
        cout << s1[ i ] << endl;
    }

    cout << "============================" << endl;

    DynamicArray<int> s2(50);
    s2 = s1;

    s2.resize(6);
    s2[ 5 ] = 100;

    for (int i = 0; i < s2.length(); i++) {
        cout << s2[ i ] << endl;
    }

    return 0;
}
