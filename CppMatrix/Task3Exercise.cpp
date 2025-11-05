#include "Task3Exercise.h"
#include <cmath>

namespace miit::algebra
{
    Matrix Task3Exercise::execute()
    {
        Matrix result(matrix.size());
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            if (i % 2 == 0) // четный индекс
                result[i] = std::abs(matrix[i] * matrix[i]);
            else // нечетный индекс
                result[i] = 2 * matrix[i];
        }
        return result;
    }
}