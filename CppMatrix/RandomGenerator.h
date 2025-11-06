#pragma once

#include "Generator.h"
#include <random>

namespace miit::algebra
{
    /**
     * @brief Генератор случайных целых чисел.
     */
    class RandomGenerator : public Generator
    {
    private:
        std::uniform_int_distribution<int> distribution;
        std::mt19937 generator;

    public:
        /**
         * @brief Конструктор.
         * @param min Минимальное значение диапазона (включительно).
         * @param max Максимальное значение диапазона (включительно).
         */
        RandomGenerator(const int min, const int max);

        /**
         * @brief Сгенерировать случайное значение.
         * @return Случайное целое в диапазоне [min, max].
         */
        int generate() override;
    };
}