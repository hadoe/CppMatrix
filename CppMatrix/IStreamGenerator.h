#pragma once

#include "Generator.h"
#include <iostream>

namespace miit::algebra
{
    /**
     * @brief Генератор из входного потока
     */
    class IStreamGenerator : public Generator
    {
    private:
        std::istream& in;

    public:
        /**
         * @brief Конструктор
         * @param in входной поток (по умолчанию std::cin)
         */
        IStreamGenerator(std::istream& in = std::cin);

        /**
         * @brief Читает значение из потока
         * @return прочитанное значение
         */
        int generate() override;
    };
}