#pragma once

#include "Matrix.h"
#include "Generator.h"
#include <memory>
#include <stdexcept>

namespace miit::algebra
{
    /**
     * @brief Базовый класс для выполнения заданий.
     */
    class Exercise
    {
    protected:
        Matrix matrix;
        std::unique_ptr<Generator> generator;

    public:
        /**
         * @brief Конструктор.
         * @param size Размер внутренней матрицы.
         * @param gen Генератор значений для заполнения матрицы.
         */
        Exercise(size_t size, std::unique_ptr<Generator> gen);

        /**
         * @brief Виртуальный деструктор.
         */
        virtual ~Exercise() = default;

        /**
         * @brief Заполнить матрицу значениями из генератора.
         */
        void fill_matrix();

        /**
         * @brief Доступ к внутренней матрице (только чтение).
         */
        const Matrix& get_matrix() const;

        /**
         * @brief Задание 1: заменить минимальный элемент на срединный.
         */
        virtual void Task1();

        /**
         * @brief Задание 2: удалить элементы с цифрой 5.
         */
        virtual void Task2();

        /**
         * @brief Задание 3: вернуть матрицу, трансформированную по правилу.
         */
        virtual Matrix Task3() const;
    };
}