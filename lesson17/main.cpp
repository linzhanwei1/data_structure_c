#include "DynamicList.h"
#include "Exception.h"
#include <iostream>

using namespace std;
using namespace DTLib;

int main(int argc, char *argv[]) {
    DynamicList<int> l(5);

    for (int i = 0; i < l.capacity(); i++) {
        l.insert(0, i);
    }

    for (int i = 0; i < l.capacity(); i++) {
        cout << l[ i ] << endl;
    }

    l[ 0 ] *= l[ 0 ];
    for (int i = 0; i < l.capacity(); i++) {
        cout << l[ i ] << endl;
    }

    try {
        l[ 5 ] = 5;
    } catch (const Exception &e) {
        cout << e.message() << e.location() << endl;
        l.resize(10);
        l.insert(5, 50);
    }

    for (int i = 0; i < l.length(); i++) {
        cout << l[ i ] << endl;
    }

    l.resize(3);
    for (int i = 0; i < l.length(); i++) {
        cout << l[ i ] << endl;
    }

    return 0;
}
