#include "TaskExercise.h"
#include <algorithm>
#include <stdexcept>

namespace miit::algebra
{
    TaskExercise::TaskExercise(size_t size, std::unique_ptr<Generator> gen)
        : Exercise(size, std::move(gen))
    {
    }

    void TaskExercise::Task1()
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
                break; // заменяем только первый найденный минимальный элемент
            }
        }
    }

    void TaskExercise::Task2()
    {
        matrix.remove_elements_with_digit_five();
    }

    Matrix TaskExercise::Task3() const
    {
        return matrix.transform_by_rule();
    }
}