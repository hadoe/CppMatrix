#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Конкретные задания (может быть расширен).
     */
    class TaskExercise : public Exercise
    {
    public:
        /**
         * @brief Наследует конструктор базового класса.
         */
        using Exercise::Exercise;
    };
}