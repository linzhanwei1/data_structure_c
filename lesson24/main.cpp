#include "LinkList.h"
#include <cstdio>
#include <iostream>

using namespace std;
using namespace DTLib;

int main(int argc, char *argv[]) {
    LinkList<int> list;

    for (int i = 0; i < 5; i++) {
        list.insert(0, i);
    }
    cout << "==================" << endl;
    for (list.move(0); !list.end(); list.next()) {
        cout << list.current() << endl;
    }

    return 0;
}
