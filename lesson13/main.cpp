#include "Exception.h"
#include <iostream>

using namespace std;
using namespace DTLib;

int main(int argc, char *argv[]) {
    InvalidOperationException *e = new InvalidOperationException();

    delete e;

    return 0;
}
