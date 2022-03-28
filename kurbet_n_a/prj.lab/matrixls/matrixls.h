#ifndef MATRIXLS_MATRIXLS_H_20201020
#define MATRIXLS_MATRIXLS_H_20201020

#include <iosfwd>
#include <vector>

class MatrixLs {
public:
    MatrixLs() = default;
    MatrixLs(const MatrixLs&) = default;
    MatrixLs(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count);
    ~MatrixLs() = default;
    MatrixLs& operator=(const MatrixLs&) = default;

    std::ptrdiff_t rowCount() const noexcept { return n_row_; }
    std::ptrdiff_t colCount() const noexcept { return n_col_; }

    float& at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col);
    float at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const;

    MatrixLs& transpose() noexcept;
    MatrixLs& multiply(MatrixLs&);

    void swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second);
    void swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second);

private:
    std::ptrdiff_t n_row_{ 0 };
    std::ptrdiff_t n_col_{ 0 };
    std::vector<float> data_;
    std::vector <std::ptrdiff_t> indexes_;
};

#endif