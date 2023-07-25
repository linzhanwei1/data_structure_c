#include "Exception.h"
#include "StaticLinkList.h"
#include <cstdio>
#include <iostream>

using namespace std;
using namespace DTLib;

int main(int argc, char *argv[]) {
    StaticLinkList<int, 5> list;

    for (int i = 0; i < 5; i++) {
        list.insert(0, i);
    }

    try {
        list.insert(10);
    } catch (const Exception &e) {
        cout << e.message() << endl;
    }
    cout << "==================" << endl;
    for (list.move(0); !list.end(); list.next()) {
        cout << list.current() << endl;
    }

    return 0;
}
