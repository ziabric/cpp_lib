#include "arrayd.h"

#include<iostream>
#include<limits>

ArrayD::ArrayD(const ArrayD& arr) {

    if (arr.size() >= 0) {
        size_ = arr.size();
        capacity_ = arr.size();
        data_ = new float[size_];
        for (std::ptrdiff_t i = 0;i < size_;i++)
            data_[i] = arr[i];
    }
    else
        throw std::logic_error("size must be more or equal than zero");
}


ArrayD::ArrayD(const std::ptrdiff_t size) {
    if (size < 0) {
        throw std::logic_error("size must be more or equal than zero");
    }
    else {
        size_ = size;
        capacity_ = size;
        data_ = new float[size];
        for (std::ptrdiff_t i = 0;i < size_;i++)
            data_[i] = 0.0f;
    }
}

ArrayD& ArrayD::operator=(const ArrayD& rhs) {
    if(rhs.data_!=data_) {
        if (rhs.size() < capacity_) {
            for (std::ptrdiff_t i = 0;i < capacity_;i++)
                data_[i] = 0.0f;
            size_ = rhs.size();
            for (std::ptrdiff_t i = 0;i < size_;i++)
                data_[i] = rhs[i];
        }
        else {
            delete[] data_;
            data_ = new float[rhs.size()];
            capacity_ = rhs.size();
            size_ = rhs.size();
            for (std::ptrdiff_t i = 0;i < rhs.size();i++)
                data_[i] = rhs[i];
        }
    }
    return *this;
}


float& ArrayD::operator[](const std::ptrdiff_t i) {
    if (i < 0 || i >= size_) {
        throw std::out_of_range("element with this number doesn't exist");
    }
    else if (size_ == 0) {
        throw std::out_of_range("array is empty");
    }
    else return data_[i];
}

const float& ArrayD::operator[](const std::ptrdiff_t i) const {
    if (i < 0 || i >= size_) {
        throw std::out_of_range("element with this number doesn't exist");
    }
    else if (size_ == 0) {
        throw std::out_of_range("array is empty");
    }
    else return data_[i];
}

void ArrayD::resize(const std::ptrdiff_t size) {
    if (size < 0) throw std::logic_error("size must be more or equal than zero");
    else{
        if (size > capacity_) {
            capacity_ = size;
            float* new_data = new float[capacity_];
            for (std::ptrdiff_t i = 0;i < size;i++) {
                new_data[i] = 0.0f;
            }
            for (std::ptrdiff_t i = 0;i < size_;i++) {
                new_data[i] = data_[i];
            }
            delete[] data_;
            data_ = new_data;
        }
        size_ = size;
    }
}