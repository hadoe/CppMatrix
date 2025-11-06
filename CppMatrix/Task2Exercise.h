#pragma once
#include "Exercise.h"
#include <vector>

namespace miit::algebra
{
    /**
     * @brief Задание 2: удалить элементы с цифрой 5.
     */
    class Task2Exercise : public Exercise
    {
    public:
        using Exercise::Exercise;

        /**
         * @brief Выполнить задание 2.
         */
        void execute() override;

        /**
         * @brief Проверка, содержит ли число цифру 5.
         */
        static bool contains_digit_five(int number);
    };
}