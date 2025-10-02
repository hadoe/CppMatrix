#include "Exercise.h"

namespace miit::algebra
{
    Exercise::Exercise(size_t size, std::unique_ptr<Generator> gen)
        : matrix(size), generator(std::move(gen))
    {
    }

    void Exercise::fill_matrix()
    {
        matrix.fill(std::move(generator));
    }

    const Matrix& Exercise::get_matrix() const
    {
        return matrix;
    }
}