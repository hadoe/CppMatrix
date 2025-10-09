#include "Exercise.h"
#include <algorithm>

namespace miit::algebra
{
    Exercise::Exercise(size_t size, std::unique_ptr<Generator> gen)
        : matrix(size), generator(std::move(gen))
    {
    }

    void Exercise::fill_matrix()
    {
        if (generator) {
            matrix.fill(std::move(generator));
        }
    }

    const Matrix& Exercise::get_matrix() const
    {
        return matrix;
    }

    void Exercise::Task1()
    {
        if (matrix.size() % 2 == 0)
            throw std::runtime_error("Matrix size must be odd for Task1");

        int min_val = matrix.min();
        int middle_val = matrix.middle();

        for (size_t i = 0; i < matrix.size(); ++i)
        {
            if (matrix[i] == min_val)
            {
                matrix[i] = middle_val;
                break;
            }
        }
    }

    void Exercise::Task2()
    {
        matrix.remove_elements_with_digit_five();
    }

    Matrix Exercise::Task3() const
    {
        return matrix.transform_by_rule();
    }
}