#include "ConstantGenerator.h"

miit::algebra::ConstantGenerator::ConstantGenerator(const int value)
    : value{ value }
{
}

int miit::algebra::ConstantGenerator::generate()
{
    return this->value;
}