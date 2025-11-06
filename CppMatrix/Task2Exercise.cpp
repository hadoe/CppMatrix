#include "Task2Exercise.h"
#include <cmath>
#include <algorithm>

namespace miit::algebra
{
    void Task2Exercise::execute()
    {
        std::vector<int> new_data;
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            if (!contains_digit_five(matrix[i]))
            {
                new_data.push_back(matrix[i]);
            }
        }

        // Создаем новую матрицу с отфильтрованными данными
        Matrix new_matrix(new_data.size());
        for (size_t i = 0; i < new_data.size(); ++i)
        {
            new_matrix[i] = new_data[i];
        }

        // Заменяем исходную матрицу на отфильтрованную
        matrix = new_matrix;
    }

    bool Task2Exercise::contains_digit_five(int number)
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
}