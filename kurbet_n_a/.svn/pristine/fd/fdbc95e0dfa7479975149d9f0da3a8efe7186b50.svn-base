#include "matrixls.h"
#include <stdexcept>
#include <iostream>

MatrixLs::MatrixLs(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count)
{
    if (col_count == 0 || row_count == 0) {
        throw std::invalid_argument("invalid_argument");
    }
    n_col_ = col_count;
    n_row_ = row_count;
    data_ = std::vector<float>(col_count * row_count);
    indexes_ = std::vector<std::ptrdiff_t>(row_count);
    for (int i = 0; i < row_count; i+=1) {
        indexes_[i] = i * col_count;
    }

}


MatrixLs& MatrixLs::transpose() noexcept
{
    MatrixLs newM(n_row_, n_col_);
    for (int i = 0; i < rowCount(); i++) {
        for (int j = 0; j < colCount(); j++) {
            newM.at(j, i) = this->at(i, j);
        }
    }
    *this = newM;
    return *this;
}

MatrixLs& MatrixLs::multiply(MatrixLs& rhs)
{
    MatrixLs newM(rhs.n_col_, n_row_);
    if (n_col_ != rhs.n_row_) throw std::invalid_argument("invalid_argument");

    for (int i = 0; i < n_row_; i+=1) {
        for (int j = 0; j < rhs.n_col_; j+=1) {
            float sum = 0;
            for (int r = 0; r < n_col_; r+=1) {
                sum += this->at(i, r) * rhs.at(r, j);
            }
            newM.at(i, j) = sum;
        }
    }
    *this = newM;

    return *this;
}

void MatrixLs::swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second)
{
    if (i_first >= n_row_ || i_first < 0 || i_second >= n_row_ || i_second < 0) {
        throw std::invalid_argument("invalid_argument");
    }
    std::ptrdiff_t c = indexes_[i_first];
    indexes_[i_first] = indexes_[i_second];
    indexes_[i_second] = c;
}

void MatrixLs::swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second)
{
    if (i_first >= n_col_ || i_first < 0 || i_second >= n_col_ || i_second < 0) {
        throw std::invalid_argument("invalid_argument");
    }
    for (int i = 0; i < rowCount(); i+=1) {
        const float c = at(i, i_first);
        at(i, i_first) = at(i, i_second);
        at(i, i_second) = c;
    }
}

float& MatrixLs::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col)
{
    if (i_row >= n_row_ || i_col >= n_col_ || i_col < 0 || i_row < 0) throw std::invalid_argument("invalid_argument");
    return data_[indexes_[i_row] + i_col];
}

float MatrixLs::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const
{
    if (i_row >= n_row_ || i_col >= n_col_ || i_col < 0 || i_row < 0) throw std::invalid_argument("invalid_argument");
    return data_[indexes_[i_row] + i_col];
}
