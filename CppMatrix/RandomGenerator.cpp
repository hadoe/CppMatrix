#include "RandomGenerator.h"

miit::algebra::RandomGenerator::RandomGenerator(const int min, const int max)
    : generator(std::random_device{}()), distribution(min, max)
{
}

int miit::algebra::RandomGenerator::generate()
{
    return this->distribution(this->generator);
}