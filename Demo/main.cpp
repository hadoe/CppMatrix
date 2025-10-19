#include <iostream>
#include <memory>
#include "Matrix.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ConstantGenerator.h"
#include "TaskExercise.h"

//Перед изменением матрицы создать её копию и уже с ней проводить операции

using namespace miit::algebra;

void run_interactive()
{
    std::cout << "=== Режим взаимодействия ===" << std::endl;

    size_t n = 0;
    std::cout << "Введите размер массива: ";
    if (!(std::cin >> n) || n == 0)
    {
        std::cout << "Некорректный размер." << std::endl;
        return;
    }

    Matrix matrix(n);
    std::cout << "Введите " << n << " целых значений: ";
    for (size_t i = 0; i < n; ++i)
    {
        int value = 0;
        if (!(std::cin >> value))
        {
            std::cout << "Ошибка ввода." << std::endl;
            return;
        }
        matrix[i] = value;
    }

    std::cout << "Выберите задание (1, 2 или 3): ";
    int task = 0;
    if (!(std::cin >> task))
    {
        std::cout << "Ошибка ввода номера задания." << std::endl;
        return;
    }

    if (task == 1)
    {
        if (matrix.size() % 2 == 0)
        {
            std::cout << "Для задания 1 размер должен быть нечётным." << std::endl;
            return;
        }

        int min_val = matrix.min();
        int middle_val = matrix.middle();
        // Создаем копию матрицы
        Matrix matrix_copy = matrix;
        for (size_t i = 0; i < matrix_copy.size(); ++i)
        {
            if (matrix_copy[i] == min_val)
            {
                matrix_copy[i] = middle_val;
                break;
            }
        }
        std::cout << "Исходная матрица: " << matrix.to_string() << std::endl;
        std::cout << "Результат (Task1): " << matrix_copy.to_string() << std::endl;
    }
    else if (task == 2)
    {
        // Создаем копию матрицы перед изменением
        Matrix matrix_copy = matrix;
        matrix_copy.remove_elements_with_digit_five();
        std::cout << "Исходная матрица: " << matrix.to_string() << std::endl;
        std::cout << "Результат (Task2): " << matrix_copy.to_string() << std::endl;
    }
    else if (task == 3)
    {
        // transform_by_rule уже возвращает новую матрицу, но для консистентности покажем исходную
        Matrix result = matrix.transform_by_rule();
        std::cout << "Исходная матрица: " << matrix.to_string() << std::endl;
        std::cout << "Результат (Task3): " << result.to_string() << std::endl;
    }
    else
    {
        std::cout << "Неизвестное задание." << std::endl;
    }

    std::cout << std::endl;
}


void demonstrate_basic_operations()
{
    std::cout << "=== Basic Matrix Operations ===" << std::endl;

    Matrix matrix{ 1, 2, 3, 4, 5 };
    std::cout << "Original: " << matrix.to_string() << std::endl;

    // Index operator
    matrix[2] = 10;
    std::cout << "After matrix[2] = 10: " << matrix.to_string() << std::endl;

    // Dereference
    std::cout << "First element: " << *matrix << std::endl;

    // Shift operations
    Matrix left = matrix << 2;
    std::cout << "Left shift 2: " << left.to_string() << std::endl;

    Matrix right = matrix >> 1;
    std::cout << "Right shift 1: " << right.to_string() << std::endl;

    std::cout << std::endl;
}

void demonstrate_generators()
{
    std::cout << "=== Generators Demo ===" << std::endl;

    // Random generator
    auto random_gen = std::make_unique<RandomGenerator>(-10, 10);
    Matrix random_matrix(5);
    random_matrix.fill(std::move(random_gen));
    std::cout << "Random matrix: " << random_matrix.to_string() << std::endl;

    // Constant generator
    auto constant_gen = std::make_unique<ConstantGenerator>(7);
    Matrix constant_matrix(4);
    constant_matrix.fill(std::move(constant_gen));
    std::cout << "Constant matrix: " << constant_matrix.to_string() << std::endl;

    std::cout << std::endl;
}

void demonstrate_tasks()
{
    std::cout << "=== Tasks Demo ===" << std::endl;

    // Task 1 with odd size
    auto gen1 = std::make_unique<RandomGenerator>(-10, 10);
    TaskExercise exercise1(5, std::move(gen1));
    exercise1.fill_matrix();

    std::cout << "Before Task1: " << exercise1.get_matrix().to_string() << std::endl;
    // Сохраняем исходную матрицу перед изменением
    Matrix original1 = exercise1.get_matrix();
    exercise1.Task1();
    std::cout << "After Task1: " << exercise1.get_matrix().to_string() << std::endl;

    // Task 2
    Matrix matrix_for_task2{ 15, 20, 25, 30, 35 };
    Matrix demo_matrix = matrix_for_task2;
    std::cout << "Before Task2: " << matrix_for_task2.to_string() << std::endl;
    demo_matrix.remove_elements_with_digit_five();
    std::cout << "After Task2: " << demo_matrix.to_string() << std::endl;

    // Task 3
    Matrix matrix_for_task3{ 1, 2, 3, 4 };
    Matrix result = matrix_for_task3.transform_by_rule();
    std::cout << "Original matrix: " << matrix_for_task3.to_string() << std::endl;
    std::cout << "Task3 result: " << result.to_string() << std::endl;
}

int main()
{
    setlocale(LC_ALL, "ru-RU");

    std::cout << "Выберите режим: 1 — демонстрация, 2 — интерактивный: ";
    int mode = 0;
    if (!(std::cin >> mode))
    {
        std::cerr << "Некорректный ввод." << std::endl;
        return 1;
    }

    switch (mode)
    {
    case 1:
        demonstrate_basic_operations();
        demonstrate_generators();
        demonstrate_tasks();
        std::cout << "=== Demo completed successfully ===" << std::endl;
        break;
    case 2:
        run_interactive();
        break;
    default:
        std::cout << "Неизвестный режим." << std::endl;
        return 1;
    }

    return 0;
}