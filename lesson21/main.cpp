#include "LinkList.h"
#include <iostream>

using namespace std;
using namespace DTLib;

int main(int argc, char *argv[]) {
    LinkList<int> list;

    for (int i = 0; i < 5; i++) {
        list.insert(i, i);
    }
    for (int i = 0; i < list.length(); i++) {
        cout << list.get(i) << endl;
    }

    cout << "============================" << endl;

    list.remove(2);
    for (int i = 0; i < list.length(); i++) {
        cout << list.get(i) << endl;
    }

    return 0;
}
