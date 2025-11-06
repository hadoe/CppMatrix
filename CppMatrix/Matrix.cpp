#include "Matrix.h"
#include <sstream>
#include <cmath>
#include <algorithm>

namespace miit::algebra
{
    Matrix::Matrix(size_t size) : data(size) {}

    Matrix::Matrix(std::initializer_list<int> initializer) : data(initializer) {}

    int& Matrix::operator[](size_t index)
    {
        if (index >= data.size()) 
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const int& Matrix::operator[](size_t index) const
    {
        if (index >= data.size()) 
        {
            throw std::out_of_range("Index out of range");
        }
            return data[index];
    }

    Matrix Matrix::operator<<(int shift) const
    {
        Matrix result(*this);
        std::rotate(result.data.begin(), result.data.begin() + shift, result.data.end());
        return result;
    }

    Matrix Matrix::operator>>(int shift) const
    {
        Matrix result(*this);
        std::rotate(result.data.rbegin(), result.data.rbegin() + shift, result.data.rend());
        return result;
    }

    size_t Matrix::size() const
    {
        return data.size();
    }

    std::string Matrix::to_string() const
    {
        std::ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < data.size(); ++i)
        {
            oss << data[i];
            if (i != data.size() - 1)
                oss << ", ";
        }
        oss << "]";
        return oss.str();
    }

    void Matrix::fill(std::unique_ptr<Generator> generator)
    {
        for (size_t i = 0; i < data.size(); ++i)
        {
            data[i] = generator->generate();
        }
    }

    
}