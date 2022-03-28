#pragma once
#ifndef MATRIXDS_H
#define MATRIXDS_H

#include <iostream>
#include <vector>


class MatrixDs {
public:
  MatrixDs() = default;
  MatrixDs(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count);
  ~MatrixDs() = default;
  MatrixDs& operator=(const MatrixDs&) = default;

  std::ptrdiff_t rowCount() const { return n_row_;}
  std::ptrdiff_t colCount() const { return n_col_;}
  float& at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col);
  float at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const;
  MatrixDs& transpose() noexcept;
  MatrixDs& multiply(MatrixDs& rhs);
  void swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second);
  void swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second);

  void print()
  {
      std::cout<<"\n";
      for (int i = 0;i <n_row_;i+=1)
      {
          for (int j = 0;j <n_col_;j+=1)
          {
               std::cout<<data_[i][j]<<"  ";
          }
          std::cout<<"\n";
      }
      std::cout<<'\n';
  }
private:
  std::ptrdiff_t n_row_ = 0;
  std::ptrdiff_t n_col_ = 0;
  std::vector<std::vector<float> > data_;
};

#endif
