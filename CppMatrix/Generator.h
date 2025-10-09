#pragma once

namespace miit::algebra
{
    /**
     * @brief Абстрактный интерфейс генератора целых чисел.
     *
     * Реализации должны предоставлять метод generate(),
     * возвращающий очередное целое значение.
     */
    class Generator
    {
    public:
        /**
         * @brief Виртуальный деструктор интерфейса.
         */
        virtual ~Generator() = default;

        /**
         * @brief Сгенерировать очередное значение.
         * @return Целое число, полученное из источника генератора.
         */
        virtual int generate() = 0;
    };
}