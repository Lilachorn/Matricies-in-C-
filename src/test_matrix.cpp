#include "matrix.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    Matrix mat0(55,2);
    Matrix mat1(3,64);
    mat0.randomize();
    mat1.randomize();
    cout << mat0 << endl;
    cout << mat1 << endl;
    cout << (mat0 & mat1) << endl;
}