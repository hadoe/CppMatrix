#pragma once

#include "Matrix.h"
#include "Generator.h"
#include <memory>

namespace miit::algebra
{
    /**
     * @brief Абстрактный класс для выполнения заданий
     */
    class Exercise
    {
    protected:
        Matrix matrix;
        std::unique_ptr<Generator> generator;

    public:
        /**
         * @brief Конструктор
         * @param size размер матрицы
         * @param gen генератор значений
         */
        Exercise(size_t size, std::unique_ptr<Generator> gen);

        /**
         * @brief Виртуальный деструктор
         */
        virtual ~Exercise() = default;

        /**
         * @brief Заполнить матрицу
         */
        void fill_matrix();

        /**
         * @brief Получить матрицу
         */
        const Matrix& get_matrix() const;

        /**
         * @brief Задание 1 (чисто виртуальный метод)
         */
        virtual void Task1() = 0;

        /**
         * @brief Задание 2 (чисто виртуальный метод)
         */
        virtual void Task2() = 0;
    };
}