#pragma once

#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief Генератор, возвращающий постоянное значение.
     */
    class ConstantGenerator : public Generator
    {
    private:
        int value;

    public:
        /**
         * @brief Конструктор.
         * @param value Постоянное значение, которое будет возвращать генератор.
         */
        ConstantGenerator(const int value);

        /**
         * @brief Вернуть постоянное значение.
         * @return Заранее заданное константное число.
         */
        int generate() override;
    };
}