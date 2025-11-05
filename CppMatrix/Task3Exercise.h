#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Задание 3: вернуть матрицу, трансформированную по правилу.
     */
    class Task3Exercise : public Exercise
    {
    public:
        using Exercise::Exercise;

        /**
         * @brief Выполнить задание 3.
         * @return Трансформированная матрица.
         */
        Matrix execute();
    };
}