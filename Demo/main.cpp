#include <iostream>
#include <memory>
#include "Matrix.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ConstantGenerator.h"
#include "TaskExercise.h"

using namespace miit::algebra;

void demonstrate_matrix_operations()
{
    std::cout << "=== Демонстрация операций с матрицей ===" << std::endl;

    // Создание и заполнение матрицы
    Matrix matrix{ 1, 2, 3, 4, 5 };
    std::cout << "Исходная матрица: " << matrix.to_string() << std::endl;

    // Оператор доступа по индексу
    matrix[2] = 10;
    std::cout << "После matrix[2] = 10: " << matrix.to_string() << std::endl;

    // Оператор разыменования
    std::cout << "Первый элемент (*matrix): " << *matrix << std::endl;

    // Операторы сдвига
    Matrix left_shifted = matrix << 2;
    std::cout << "Сдвиг влево на 2: " << left_shifted.to_string() << std::endl;

    Matrix right_shifted = matrix >> 1;
    std::cout << "Сдвиг вправо на 1: " << right_shifted.to_string() << std::endl;

    std::cout << std::endl;
}

void demonstrate_generators()
{
    std::cout << "=== Демонстрация генераторов ===" << std::endl;

    // Генератор случайных чисел
    auto random_gen = std::make_unique<RandomGenerator>(-1000, 1000);
    Matrix random_matrix(5);
    random_matrix.fill(std::move(random_gen));
    std::cout << "Матрица со случайными числами: " << random_matrix.to_string() << std::endl;

    // Генератор постоянных значений
    auto constant_gen = std::make_unique<ConstantGenerator>(7);
    Matrix constant_matrix(4);
    constant_matrix.fill(std::move(constant_gen));
    std::cout << "Матрица с постоянными значениями: " << constant_matrix.to_string() << std::endl;

    std::cout << std::endl;
}

void demonstrate_tasks()
{
    std::cout << "=== Демонстрация выполнения заданий ===" << std::endl;

    // Задание с нечетным размером для Task1
    auto gen1 = std::make_unique<RandomGenerator>(-100, 100);
    TaskExercise exercise1(7, std::move(gen1));
    exercise1.fill_matrix();

    std::cout << "Матрица для заданий (нечетный размер): " << exercise1.get_matrix().to_string() << std::endl;

    // Выполнение Task1
    exercise1.Task1();
    std::cout << "После Task1 (замена минимального на средний): " << exercise1.get_matrix().to_string() << std::endl;

    // Задание с четным размером для Task2 и Task3
    auto gen2 = std::make_unique<ConstantGenerator>(15); // содержит цифру 5
    TaskExercise exercise2(6, std::move(gen2));
    exercise2.fill_matrix();

    std::cout << "Матрица для Task2 и Task3: " << exercise2.get_matrix().to_string() << std::endl;

    // Выполнение Task2
    exercise2.Task2();
    std::cout << "После Task2 (удаление элементов с цифрой 5): " << exercise2.get_matrix().to_string() << std::endl;

    // Выполнение Task3
    Matrix result3 = exercise2.Task3();
    std::cout << "После Task3 (преобразование по правилу): " << result3.to_string() << std::endl;
}

int main()
{
    try
    {
        demonstrate_matrix_operations();
        demonstrate_generators();
        demonstrate_tasks();

        std::cout << "=== Демонстрация завершена ===" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}