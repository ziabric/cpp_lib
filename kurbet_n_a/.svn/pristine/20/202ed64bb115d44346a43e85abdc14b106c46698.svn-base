#include "matrixds.h"

#include <iostream>
#include <stdexcept>

MatrixDs::MatrixDs(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count)
{
    if (col_count == 0 || row_count == 0) {
        throw std::invalid_argument("invalid_argument");
    }
    data_ = std::vector<std::vector<float>> (row_count, std::vector<float>(col_count));
    n_row_ = row_count;
    n_col_ = col_count;
}

MatrixDs& MatrixDs::transpose() noexcept
{
    MatrixDs newM(n_row_, n_col_);
    for (int i = 0; i < rowCount(); i++) {
        for (int j = 0; j < colCount(); j++) {
            newM.at(j, i) = at(i, j);
        }
    }
    *this = newM;
    return *this;
}

MatrixDs& MatrixDs::multiply(MatrixDs& rhs)
{
    MatrixDs newM(rhs.n_col_, n_row_);
    if (n_col_ != rhs.n_row_) {
        throw std::invalid_argument("invalid_argument");
    }

    for (int i = 0; i < n_row_; i++) {
        for (int j = 0; j < rhs.n_col_; j++) {
            float sum = 0;
            for (int r = 0; r < n_col_; r++) {
                sum += at(i, r) * rhs.at(r, j);
            }
            newM.at(i, j) = sum;
        }
    }
    *this = newM;

    return *this;
}

void MatrixDs::swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second)
{
    if (i_first >= n_row_ || i_first < 0 || i_second >= n_row_ || i_second < 0) throw std::invalid_argument("invalid_argument");
    for (int i = 0; i < n_col_; i++) {
        const float c = at(i_first, i);
        at(i_first, i) = at(i_second, i);
        at(i_second, i) = c;
    }
}

void MatrixDs::swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second)
{
    if (i_first >= n_col_ || i_first < 0 || i_second >= n_col_ || i_second < 0) throw std::invalid_argument("invalid_argument");
    for (int i = 0; i < n_row_; i++) {
        const float c = at(i, i_first);
        at(i, i_first) = at(i, i_second);
        at(i, i_second) = c;
    }
}



float& MatrixDs::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col)
{
    if (i_row >= n_row_ || i_col >= n_col_ || i_col < 0 || i_row < 0) {
        throw std::invalid_argument("invalid_argument");
    }
    return data_[i_row][i_col];
}
float MatrixDs::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const
{
    if (i_row >= n_row_ || i_col >= n_col_ || i_col < 0 || i_row < 0) {
        throw std::invalid_argument("invalid_argument");
    }
    return data_[i_row][i_col];
}

