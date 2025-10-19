#pragma once

#include <vector>
#include <string>
#include <memory>
#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief Одномерная матрица (список целых значений).
     */
    class Matrix
    {
    private:
        std::vector<int> data;

    public:
        /**
         * @brief Конструктор по умолчанию.
         */
        Matrix() = default;

        /**
         * @brief Конструктор копирования.
         */
        Matrix(const Matrix&) = default;

        /**
         * @brief Конструктор перемещения.
         */
        Matrix(Matrix&&) = default;

        /**
         * @brief Конструктор по размеру.
         * @param size Количество элементов матрицы.
         */
        explicit Matrix(size_t size);

        /**
         * @brief Конструктор из списка инициализации.
         * @param initializer Значения для начальной инициализации.
         */
        Matrix(std::initializer_list<int> initializer);

        /**
         * @brief Деструктор.
         */
        ~Matrix() = default;

        /**
         * @brief Оператор присваивания копированием.
         */
        Matrix& operator=(const Matrix&) = default;

        /**
         * @brief Оператор присваивания перемещением.
         */
        Matrix& operator=(Matrix&&) = default;

        /**
         * @brief Доступ к элементу по индексу.
         */
        int& operator[](size_t index);
        const int& operator[](size_t index) const;

        /**
         * @brief Разыменование — первый элемент.
         */
        int& operator*();
        const int& operator*() const;

        /**
         * @brief Циклический сдвиг влево.
         */
        Matrix operator<<(int shift) const;

        /**
         * @brief Циклический сдвиг вправо.
         */
        Matrix operator>>(int shift) const;

        /**
         * @brief Размер матрицы (число элементов).
         */
        size_t size() const;

        /**
         * @brief Представление в виде строки.
         */
        std::string to_string() const;

        /**
         * @brief Заполнить матрицу значениями из генератора.
         * @param generator Указатель на генератор значений.
         */
        void fill(std::unique_ptr<Generator> generator);

        /**
         * @brief Минимальный элемент.
         */
        int min() const;

        /**
         * @brief Срединный элемент (для нечётного размера).
         */
        int middle() const;

        /**
         * @brief Среднее арифметическое.
         */
        double average() const;

        /**
         * @brief Проверка, содержит ли число цифру 5.
         * @param number Число для проверки.
         */
        static bool contains_digit_five(int number);

        /**
         * @brief Удалить элементы, содержащие цифру 5.
         */
        void remove_elements_with_digit_five();

        /**
         * @brief Трансформация по правилу из задания 3.
         */
        Matrix transform_by_rule() const;
    };
}