#ifndef MATRIX
#define MATRIX

#include <vector>

class Matrix {
public:
    Matrix(int);
    Matrix(int, int);

    void print() const;
private:
    int nbrRows;
    int nbrCols;

    std::vector<std::vector<int>> mat;
};

#endif