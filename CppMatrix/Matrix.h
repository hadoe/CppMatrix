#pragma once

#include <vector>
#include <string>
#include <memory>
#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief Одномерный массив (матрица-строка)
     */
    class Matrix
    {
    private:
        std::vector<int> data;

    public:
        /**
         * @brief Конструкторы по умолчанию
         */
        Matrix() = default;
        Matrix(const Matrix&) = default;
        Matrix(Matrix&&) = default;

        /**
         * @brief Конструктор с размером
         * @param size размер массива
         */
        explicit Matrix(size_t size);

        /**
         * @brief Конструктор с инициализацией
         * @param initializer список инициализации
         */
        Matrix(std::initializer_list<int> initializer);

        /**
         * @brief Деструктор
         */
        ~Matrix() = default;

        /**
         * @brief Оператор присваивания
         */
        Matrix& operator=(const Matrix&) = default;
        Matrix& operator=(Matrix&&) = default;

        /**
         * @brief Оператор доступа по индексу
         */
        int& operator[](size_t index);
        const int& operator[](size_t index) const;

        /**
         * @brief Оператор разыменования
         */
        int& operator*();
        const int& operator*() const;

        /**
         * @brief Операторы сдвига
         */
        Matrix operator<<(int shift) const;
        Matrix operator>>(int shift) const;

        /**
         * @brief Получить размер массива
         */
        size_t size() const;

        /**
         * @brief Преобразовать в строку
         */
        std::string to_string() const;

        /**
         * @brief Заполнить массив с помощью генератора
         * @param generator генератор значений
         */
        void fill(std::unique_ptr<Generator> generator);

        /**
         * @brief Получить минимальный элемент
         */
        int min() const;

        /**
         * @brief Получить средний элемент (для нечетного размера)
         */
        int middle() const;

        /**
         * @brief Получить среднее арифметическое
         */
        double average() const;

        /**
         * @brief Проверить, содержит ли число цифру 5
         * @param number число для проверки
         */
        static bool contains_digit_five(int number);

        /**
         * @brief Удалить элементы, содержащие цифру 5
         */
        void remove_elements_with_digit_five();

        /**
         * @brief Применить преобразование по правилу задания 3
         */
        Matrix transform_by_rule() const;
    };
}