#include <iostream>
#include <memory>
#include "Matrix.h"
#include "Task1Exercise.h"
#include "Task2Exercise.h"
#include "Task3Exercise.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ConstantGenerator.h"

using namespace miit::algebra;

/**
 * @brief Enum для выбора задания
 */
enum class TaskChoice {
    TASK1 = 1,
    TASK2 = 2,
    TASK3 = 3,
    EXIT = 0
};

/**
 * @brief Enum для выбора метода ввода
 */
enum class InputMethod {
    MANUAL = 1,
    GENERATOR = 2,
    BACK = 0
};

/**
 * @brief Enum для выбора типа генератора
 */
enum class GeneratorType {
    RANDOM = 1,
    CONSTANT = 2,
    BACK = 0
};

/**
 * @brief Выбор метода ввода данных
 */
std::unique_ptr<Generator> choose_input_method() {
    InputMethod method;

    do {
        std::cout << "\nВыберите метод ввода:\n"
            << (int)InputMethod::MANUAL << ". Ручной ввод\n"
            << (int)InputMethod::GENERATOR << ". Генератор\n"
            << (int)InputMethod::BACK << ". Назад\n"
            << "Ваш выбор (0-2): ";

        int input;
        std::cin >> input;
        method = static_cast<InputMethod>(input);

        switch (method) {
        case InputMethod::MANUAL:
            return std::make_unique<IStreamGenerator>();
        case InputMethod::GENERATOR: {
            GeneratorType gen_type;

            do {
                std::cout << "\nВыберите тип генератора:\n"
                    << (int)GeneratorType::RANDOM << ". Случайный генератор\n"
                    << (int)GeneratorType::CONSTANT << ". Генератор констант\n"
                    << (int)GeneratorType::BACK << ". Назад\n"
                    << "Ваш выбор (0-2): ";

                std::cin >> input;
                gen_type = static_cast<GeneratorType>(input);

                switch (gen_type) {
                case GeneratorType::RANDOM:
                    return std::make_unique<RandomGenerator>(-1000, 1000);
                case GeneratorType::CONSTANT: {
                    int value;
                    std::cout << "Введите постоянное значение: ";
                    std::cin >> value;
                    return std::make_unique<ConstantGenerator>(value);
                }
                case GeneratorType::BACK:
                    break;
                default:
                    std::cout << "Неверный ввод\n";
                    break;
                }
            } while (gen_type != GeneratorType::BACK);
            break;
        }
        case InputMethod::BACK:
            return nullptr;
        default:
            std::cout << "Неверный ввод\n";
            break;
        }
    } while (method != InputMethod::BACK);

    return nullptr;
}

/**
 * @brief Выполнение задания 1
 */
void execute_task1(std::unique_ptr<Generator> generator, size_t size) {
    if (!generator) return;

    std::cout << "\n=== Задание 1: Замена минимального элемента на срединный ===\n";

    if (size % 2 == 0) {
        std::cout << "Ошибка: размер должен быть нечетным!\n";
        return;
    }

    Task1Exercise exercise(size, std::move(generator));

    std::cout << "Исходная матрица: " << exercise.get_matrix().to_string() << std::endl;

    exercise.execute();
}

/**
 * @brief Выполнение задания 2
 */
void execute_task2(std::unique_ptr<Generator> generator, size_t size) {
    if (!generator) return;

    std::cout << "\n=== Задание 2: Удаление элементов с цифрой 5 ===\n";

    Task2Exercise exercise(size, std::move(generator));

    std::cout << "Исходная матрица: " << exercise.get_matrix().to_string() << std::endl;

    exercise.execute();
}

/**
 * @brief Выполнение задания 3
 */
void execute_task3(std::unique_ptr<Generator> generator, size_t size) {
    if (!generator) return;

    std::cout << "\n=== Задание 3: Трансформация матрицы ===\n";

    Task3Exercise exercise(size, std::move(generator));

    std::cout << "Исходная матрица: " << exercise.get_matrix().to_string() << std::endl;
    
    exercise.execute();
}

/**
 * @brief Интерактивный режим работы
 */
void run_interactive() {

    size_t size;
    std::cout << "Введите размер матрицы: ";
    std::cin >> size;

    TaskChoice choice;

    do {
        std::cout << "\nВыберите какую задачу хотите выполнить:\n"
            << (int)TaskChoice::TASK1 << ". Task 1 - Заменить минимальный элемент на средний\n"
            << (int)TaskChoice::TASK2 << ". Task 2 - Убрать элементы с цифрой 5\n"
            << (int)TaskChoice::TASK3 << ". Task 3 - Трансформировать по правилу задания 3\n"
            << (int)TaskChoice::EXIT << ". Выход из программы\n"
            << "Ваш выбор (0-3): ";

        int input;
        std::cin >> input;
        choice = static_cast<TaskChoice>(input);

        switch (choice) {
        case TaskChoice::TASK1: {
            auto generator = choose_input_method();
            if (generator) execute_task1(std::move(generator), size);
            break;
        }
        case TaskChoice::TASK2: {
            auto generator = choose_input_method();
            if (generator) execute_task2(std::move(generator), size);
            break;
        }
        case TaskChoice::TASK3: {
            auto generator = choose_input_method();
            if (generator) execute_task3(std::move(generator), size);
            break;
        }
        case TaskChoice::EXIT:
            std::cout << "Выход из программы.\n";
            return;
        default:
            std::cout << "Неверный ввод\n";
            break;
        }
    } while (choice != TaskChoice::EXIT);
}

/**
 * @brief Главная функция программы
 */
int main() {
    setlocale(LC_ALL, "ru-RU");
    try {
        run_interactive();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}