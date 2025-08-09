#ifndef MATRIX
#define MATRIX

#include <vector>
#include <initializer_list>

class Matrix {
public:
    Matrix(int);
    Matrix(int, int);
    Matrix(std::initializer_list<double>);
    Matrix(std::initializer_list<std::initializer_list<double>>);

    void print() const;
private:
    int n_rows;
    int n_cols;

    std::vector<std::vector<int>> mat;
};

#endif