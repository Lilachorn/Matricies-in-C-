#ifndef MATRIX
#define MATRIX

#include <iostream>
#include <vector>
#include <utility>

class Matrix {
public:
    Matrix(int);
    Matrix(int, int);
    Matrix(std::initializer_list<double>);
    Matrix(std::initializer_list<std::initializer_list<double>>);

    std::vector<double>& operator[](int);
    const std::vector<double>& operator[](int) const;
    double& operator()(int,int);
    const double& operator()(int,int) const;

    Matrix& operator=(std::initializer_list<std::initializer_list<double>>);

    Matrix operator+(const Matrix&) const;
    Matrix operator*(const double) const;
    Matrix operator*(const double);
    Matrix operator*(const Matrix&) const;

    std::pair<int,int> dims() const;

    void print() const;

private:
    int n_rows;
    int n_cols;
    std::vector<std::vector<double>> mat;
};

bool operator==(const Matrix, const Matrix);
bool operator!=(const Matrix, const Matrix);
std::ostream& operator<<(std::ostream&, const Matrix&);

#endif