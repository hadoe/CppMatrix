#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Задание 1: заменить минимальный элемент на срединный.
     */
    class Task1Exercise : public Exercise
    {
    public:
        using Exercise::Exercise;

        /**
         * @brief Выполнить задание 1.
         */
        void execute();

    private:
        /**
         * @brief Найти минимальный элемент в матрице.
         */
        int min() const;

        /**
         * @brief Найти срединный элемент (для нечётного размера).
         */
        int mid() const;
    };
}