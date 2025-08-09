#include "matrix.h"
#include <iostream>
#include <cmath>

Matrix::Matrix(int dims): nbrRows{dims}, nbrCols{dims} {
    for (int i = 0; i < std::pow(dims,2); i++) {
        mat.at(i%5).push_back(0);
    }
}

Matrix::Matrix(int rows, int cols): nbrRows{rows}, nbrCols{cols} {}

void Matrix::print() const {
    for (int row = 0; row < nbrRows; row++) {
        for (int col = 0; col < nbrCols; col++) {
            std::cout << mat.at(row).at(col) << ", ";
        }
        std::cout << "\n";
    }
    std::cout << "Number of rows: " << nbrRows << "\n";
    std::cout << "Numbr of collumns: " << nbrCols<< "\n"; 
}