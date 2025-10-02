#pragma once

#include "Generator.h"
#include <random>

namespace miit::algebra
{
    /**
     * @brief √енератор случайных чисел
     */
    class RandomGenerator : public Generator
    {
    private:
        std::uniform_int_distribution<int> distribution;
        std::mt19937 generator;

    public:
        /**
         * @brief  онструктор
         * @param min минимальное значение
         * @param max максимальное значение
         */
        RandomGenerator(const int min, const int max);

        /**
         * @brief √енерирует случайное число
         * @return случайное число в диапазоне [min, max]
         */
        int generate() override;
    };
}