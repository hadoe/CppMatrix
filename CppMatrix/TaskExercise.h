#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Реализация конкретных заданий
     */
    class TaskExercise : public Exercise
    {
    public:
        /**
         * @brief Конструктор
         * @param size размер матрицы
         * @param gen генератор значений
         */
        TaskExercise(size_t size, std::unique_ptr<Generator> gen);

        /**
         * @brief Задание 1: Заменить минимальный элемент на средний
         */
        void Task1() override;

        /**
         * @brief Задание 2: Удалить элементы с цифрой 5
         */
        void Task2() override;

        /**
         * @brief Задание 3: Преобразовать по правилу
         * @return преобразованная матрица
         */
        Matrix Task3() const;
    };
}