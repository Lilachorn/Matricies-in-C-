#include "matrix.h"
#include <iostream>
#include <vector>
#include <exception>
#include <utility>

Matrix::Matrix(int entries):
    Matrix(entries, entries) {}

Matrix::Matrix(int c_n_rows, int c_n_cols):
    n_rows{c_n_rows}, n_cols{c_n_cols},
    mat(c_n_rows, std::vector<double>(c_n_cols, 0)) {}

Matrix::Matrix(std::initializer_list<double> entries):
    n_rows{static_cast<int>(entries.size())}, n_cols{static_cast<int>(entries.size())},
    mat(static_cast<int>(entries.size()), std::vector<double>(entries)) {}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> c_mat):
    n_rows{static_cast<int>(c_mat.size())}, n_cols{static_cast<int>(c_mat.begin()->size())}
{
    std::vector<double> row;
    for (auto row_itr = c_mat.begin(); row_itr != c_mat.end(); row_itr++) {
        if (row_itr->size() != c_mat.begin()->size()) {
            throw std::range_error("Rows cannot have different leanghts.");
        }
        for (auto col_itr = row_itr->begin(); col_itr != row_itr->end(); col_itr++) {
            row.emplace_back(*col_itr);
        }
        mat.emplace_back(row);
        row.clear();
    }
}

std::vector<double>& Matrix::operator[](int row) {
    return(mat[row]);
}
const std::vector<double>& Matrix::operator[](int row) const {
    return(mat[row]);
}
double& Matrix::operator()(int row, int col) {
    return(mat[row][col]);
}
const double& Matrix::operator()(int row, int col) const {
    return(mat[row][col]);
}

Matrix& Matrix::operator=(std::initializer_list<std::initializer_list<double>> new_mat) {
    Matrix temp(new_mat);
    return *this = temp;
}

Matrix Matrix::operator+(const Matrix& mat_rhs) const {
    if (this->dims() != mat_rhs.dims()) {
        throw std::range_error("Left hand side and right hand side must have the same dimensions");
    }
    Matrix res(n_rows,n_cols);
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            res[i][j] += mat_rhs[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator*(const double nbr) const {
    Matrix res(n_rows,n_cols);
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            res[i][j] = (*this)[i][j] * nbr;
        }
    }
    return res;
}

Matrix Matrix::operator*(const double nbr) {
    Matrix res(n_rows,n_cols);
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            res[i][j] = (*this)[i][j] * nbr;
        }
    }
    return res;
}

std::pair<int,int> Matrix::dims() const {
    return std::pair<int,int>(n_rows,n_cols);
}

void Matrix::print() const {
    for (int row = 0; row < n_rows; row++) {
        for (int col = 0; col < n_cols; col++) {
            std::cout << mat.at(row).at(col);
            if (col != n_cols - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }

    std::cout << "Number of rows: " << n_rows << "\n";
    std::cout << "Numbr of collumns: " << n_cols<< "\n";
}

bool operator==(const Matrix mat_lhs, const Matrix mat_rhs) {
    std::pair<int,int> lhs = mat_lhs.dims();
    std::pair<int,int> rhs = mat_rhs.dims();
    if (lhs != rhs) {
        return false;
    }
    for (int row = 0; row < lhs.first; row++) {
        for (int col = 0; col < lhs.second; col++) {
            if (mat_lhs[row][col] != mat_rhs[row][col]) {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const Matrix mat_lhs, const Matrix mat_rhs) {
    return !(mat_lhs == mat_rhs);
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
    auto dims = mat.dims();
    int n_rows = dims.first;
    int n_cols = dims.second;
    for (int row = 0; row < n_rows; row++) {
        for (int col = 0; col < n_cols; col++) {
            os << mat[row][col];
            if (col != n_cols - 1) {
                os << ", ";
            }
        }
        if (row != n_rows - 1) {
            os << "\n";
        }
    }
    return os;
}