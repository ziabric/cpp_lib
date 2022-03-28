#pragma once
#ifndef ARRAYD_H
#define ARRAYD_H

#include <cstddef>

class ArrayD {
public:
    ArrayD() = default;
    ArrayD(const ArrayD& arr);
    explicit ArrayD(const std::ptrdiff_t size);
    ~ArrayD() { delete[] data_; }
    ArrayD& operator=(const ArrayD& rhs);
    std::ptrdiff_t size() const { return size_; }
    float& operator[](const std::ptrdiff_t i);
    const float& operator[](const std::ptrdiff_t i) const;
    void resize(const std::ptrdiff_t size);
private:
    std::ptrdiff_t capacity_{0}; //емкость
    std::ptrdiff_t size_{0}; //размер
    float* data_{nullptr};
};
#endif