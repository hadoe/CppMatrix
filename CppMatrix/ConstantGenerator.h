#pragma once

#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief √енератор посто€нных значений
     */
    class ConstantGenerator : public Generator
    {
    private:
        int value;

    public:
        /**
         * @brief  онструктор
         * @param value посто€нное значение
         */
        ConstantGenerator(const int value);

        /**
         * @brief ¬озвращает посто€нное значение
         * @return посто€нное значение
         */
        int generate() override;
    };
}