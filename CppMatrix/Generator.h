#pragma once

namespace miit::algebra
{
    /**
     * @brief Абстрактный генератор значений
     */
    class Generator
    {
    public:
        /**
         * @brief Виртуальный деструктор
         */
        virtual ~Generator() = 0 {};

        /**
         * @brief Генерирует значение
         * @return сгенерированное значение
         */
        virtual int generate() = 0;
    };
}