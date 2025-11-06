#pragma once

#include "Generator.h"
#include <iostream>

namespace miit::algebra
{
    /**
     * @brief Генератор, читающий значения из входного потока.
     */
    class IStreamGenerator : public Generator
    {
    private:
        std::istream& in;

    public:
        /**
         * @brief Конструктор.
         * @param in Входной поток (по умолчанию std::cin).
         */
        IStreamGenerator(std::istream& in = std::cin);

        /**
         * @brief Считать следующее значение из потока.
         * @return Прочитанное из потока целое число.
         */
        int generate() override;
    };
}