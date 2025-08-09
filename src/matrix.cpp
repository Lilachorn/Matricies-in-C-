#include "matrix.h"
#include <iostream>
#include <cmath>
#include <vector>

Matrix::Matrix(int entries):
    Matrix(entries, entries) {}

Matrix::Matrix(int c_n_rows, int c_n_cols):
    n_rows{c_n_rows}, n_cols{c_n_cols},
    mat(c_n_rows, std::vector<int>(c_n_cols, 0)) {}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> c_mat) {
    
}

void Matrix::print() const {
    for (int row = 0; row < n_rows; row++) {
        for (int col = 0; col < n_cols; col++) {
            std::cout << mat.at(row).at(col) << ", ";
        }
        std::cout << "\n";
    }
    std::cout << "Number of rows: " << n_rows << "\n";
    std::cout << "Numbr of collumns: " << n_cols<< "\n"; 
}