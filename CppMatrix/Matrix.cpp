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
        return data[index];
    }

    const int& Matrix::operator[](size_t index) const
    {
        return data[index];
    }

    int& Matrix::operator*()
    {
        return data.front();
    }

    const int& Matrix::operator*() const
    {
        return data.front();
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

    int Matrix::min() const
    {
        if (data.empty())
            throw std::runtime_error("Matrix is empty");

        return *std::min_element(data.begin(), data.end());
    }

    int Matrix::middle() const
    {
        if (data.empty())
            throw std::runtime_error("Matrix is empty");
        if (data.size() % 2 == 0)
            throw std::runtime_error("Matrix size is even, no middle element");

        return data[data.size() / 2];
    }

    double Matrix::average() const
    {
        if (data.empty())
            return 0.0;

        double sum = 0.0;
        for (int value : data)
        {
            sum += value;
        }
        return sum / data.size();
    }

    bool Matrix::contains_digit_five(int number)
    {
        if (number == 0)
            return false;

        int num = std::abs(number);
        while (num > 0)
        {
            if (num % 10 == 5)
                return true;
            num /= 10;
        }
        return false;
    }

    void Matrix::remove_elements_with_digit_five()
    {
        data.erase(
            std::remove_if(data.begin(), data.end(),
                [](int value) { return contains_digit_five(value); }),
            data.end()
        );
    }

    Matrix Matrix::transform_by_rule() const
    {
        Matrix result(data.size());
        for (size_t i = 0; i < data.size(); ++i)
        {
            if (i % 2 == 0) // четный индекс
                result[i] = std::abs(data[i] * data[i]);
            else // нечетный индекс
                result[i] = 2 * data[i];
        }
        return result;
    }
}