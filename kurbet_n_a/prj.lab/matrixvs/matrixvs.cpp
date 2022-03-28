#include "matrixvs.h"
#include <stdexcept>
#include <iostream>

MatrixVs::MatrixVs(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count)
{
    if (col_count == 0 || row_count == 0) {
        throw std::invalid_argument("invalid_argument");
    }
    data_ = std::vector<float> (col_count * row_count);
    n_row_ = row_count;
    n_col_ = col_count;

}

float& MatrixVs::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col)
{
    if (i_row >= n_row_ || i_col >= n_col_ || i_col < 0 || i_row < 0) {
        throw std::invalid_argument("invalid_argument");
    }
    float& a = data_[i_row * colCount() + i_col];
    return a;
}

float MatrixVs::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const
{
    if (i_row >= n_row_ || i_col >= n_col_ || i_col < 0 || i_row < 0) {
        throw std::invalid_argument("invalid_argument");
    }
    const float a = data_[i_row * colCount() + i_col];
    return a;
}

MatrixVs& MatrixVs::transpose() noexcept
{
    MatrixVs newM(n_row_, n_col_);
    for (int i = 0; i < data_.size(); i++) {
        ptrdiff_t row = i / n_col_;
        ptrdiff_t col = i % n_col_;
        newM.at(col, row) = data_[i];
    }
    *this = newM;
    return *this;
}

MatrixVs& MatrixVs::multiply(const MatrixVs& rhs)
{
    MatrixVs newM(rhs.n_col_, n_row_);
    if (n_col_ != rhs.n_row_) throw std::invalid_argument("cant multiply");
    for (int i = 0; i < n_row_; i+=1) {
        for (int j = 0; j < rhs.n_col_; j+=1) {
            float sum = 0;
            for (int r = 0; r < n_col_; r += 1) {
                sum += this->at(i, r) * rhs.at(r, j);
            }
            newM.at(i, j) = sum;
        }
    }
    *this = newM;
    return *this;
}

void MatrixVs::swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second)
{
    if (i_first >= n_row_ || i_first < 0 || i_second >= n_row_ || i_second < 0) {
        throw std::invalid_argument("invalid_argument");
    }
    for (int i = 0; i < n_col_; i++) {
        float c = at(i_first, i);
        at(i_first, i) = at(i_second, i);
        at(i_second, i) = c;
    }
}

void MatrixVs::swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second)
{
    if (i_first >= n_col_ || i_first < 0 || i_second >= n_col_ || i_second < 0) {
        throw std::invalid_argument("invalid_argument");
    }
    for (int i = 0; i < n_row_; i++) {
        float c = at(i, i_first);
        at(i, i_first) = at(i, i_second);
        at(i, i_second) = c;
    }
}


