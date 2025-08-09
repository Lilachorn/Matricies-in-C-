#include "matrix.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    Matrix mat({1,2,3});
    int num = 3;
    auto res = mat*num;
    cout << mat << "\n*" << num << "=\n" << (mat*num) << endl;
}