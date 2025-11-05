#include "Task1Exercise.h"
#include <algorithm>
#include <stdexcept>

namespace miit::algebra
{
    void Task1Exercise::execute()
    {
        int min_val = min();
        int middle_val = mid();

        for (size_t i = 0; i < matrix.size(); ++i)
        {
            if (matrix[i] == min_val)
            {
                matrix[i] = middle_val;
                break;
            }
        }
    }

    int Task1Exercise::min() const
    {
        if (matrix.size() == 0)
            throw std::runtime_error("Matrix is empty");

        int min_val = matrix[0];
        for (size_t i = 1; i < matrix.size(); ++i)
        {
            if (matrix[i] < min_val)
                min_val = matrix[i];
        }
        return min_val;
    }

    int Task1Exercise::mid() const
    {
        if (matrix.size() == 0)
            throw std::runtime_error("Matrix is empty");
        if (matrix.size() % 2 == 0)
            throw std::runtime_error("Matrix size is even, no middle element");

        return matrix[matrix.size() / 2];
    }
}