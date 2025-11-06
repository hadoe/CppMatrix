#include "CppUnitTest.h"
#include "Matrix.h"
#include "RandomGenerator.h"
#include "ConstantGenerator.h"
#include "Exercise.h"
#include "Task1Exercise.h"
#include "Task2Exercise.h"
#include "Task3Exercise.h"
#include <stdexcept>
#include <sstream>
#include <IStreamGenerator.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixTest
{
    TEST_CLASS(MatrixTest)
    {
    public:
        TEST_METHOD(DefaultConstructor)
        {
            miit::algebra::Matrix matrix;
            Assert::AreEqual(size_t(0), matrix.size());
            Assert::AreEqual(std::string("[]"), matrix.to_string());
        }

        TEST_METHOD(SizeConstructor)
        {
            miit::algebra::Matrix matrix(5);
            Assert::AreEqual(size_t(5), matrix.size());
        }

        TEST_METHOD(InitializerListConstructor)
        {
            miit::algebra::Matrix matrix{ 1, 2, 3 };
            Assert::AreEqual(std::string("[1, 2, 3]"), matrix.to_string());
        }

        TEST_METHOD(CopyConstructor)
        {
            miit::algebra::Matrix original{ 1, 2, 3 };
            miit::algebra::Matrix copy(original);

            Assert::AreEqual(original.to_string(), copy.to_string());
        }

        TEST_METHOD(MoveConstructor)
        {
            miit::algebra::Matrix original{ 1, 2, 3 };
            miit::algebra::Matrix moved(std::move(original));

            Assert::AreEqual(std::string("[1, 2, 3]"), moved.to_string());
        }

        TEST_METHOD(AssignmentOperator)
        {
            miit::algebra::Matrix original{ 1, 2, 3 };
            miit::algebra::Matrix copy;
            copy = original;

            Assert::AreEqual(original.to_string(), copy.to_string());
        }

        TEST_METHOD(IndexOperator)
        {
            miit::algebra::Matrix matrix{ 1, 2, 3 };

            Assert::AreEqual(1, matrix[0]);
            Assert::AreEqual(2, matrix[1]);
            Assert::AreEqual(3, matrix[2]);

            matrix[1] = 10;
            Assert::AreEqual(10, matrix[1]);
        }

        TEST_METHOD(IndexOperator_OutOfRange)
        {
            miit::algebra::Matrix matrix{ 1, 2, 3 };

            auto func = [&matrix]() { matrix[5]; };
            Assert::ExpectException<std::out_of_range>(func);
        }

        TEST_METHOD(ShiftLeftOperator)
        {
            miit::algebra::Matrix matrix{ 1, 2, 3, 4, 5 };
            miit::algebra::Matrix result = matrix << 2;

            Assert::AreEqual(std::string("[3, 4, 5, 1, 2]"), result.to_string());
        }

        TEST_METHOD(ShiftRightOperator)
        {
            miit::algebra::Matrix matrix{ 1, 2, 3, 4, 5 };
            miit::algebra::Matrix result = matrix >> 2;

            Assert::AreEqual(std::string("[4, 5, 1, 2, 3]"), result.to_string());
        }

        TEST_METHOD(ToString)
        {
            miit::algebra::Matrix list{ 1, 2, 3 };
            Assert::AreEqual(std::string("[1, 2, 3]"), list.to_string());

            miit::algebra::Matrix empty;
            Assert::AreEqual(std::string("[]"), empty.to_string());
        }

        TEST_METHOD(FillConstantGenerator)
        {
            miit::algebra::Matrix matrix(3);
            auto generator = std::make_unique<miit::algebra::ConstantGenerator>(7);
            matrix.fill(std::move(generator));

            Assert::AreEqual(std::string("[7, 7, 7]"), matrix.to_string());
        }
    };

    TEST_CLASS(GeneratorTest)
    {
    public:
        TEST_METHOD(RandomGenerator)
        {
            miit::algebra::RandomGenerator generator(-100, 100);
            int value = generator.generate();

            Assert::IsTrue(value >= -100 && value <= 100);
        }

        TEST_METHOD(ConstantGenerator)
        {
            miit::algebra::ConstantGenerator generator(42);

            Assert::AreEqual(42, generator.generate());
            Assert::AreEqual(42, generator.generate());
            Assert::AreEqual(42, generator.generate());
        }

        TEST_METHOD(IStreamGenerator)
        {
            std::istringstream input("10 20 30");
            miit::algebra::IStreamGenerator generator(input);

            Assert::AreEqual(10, generator.generate());
            Assert::AreEqual(20, generator.generate());
            Assert::AreEqual(30, generator.generate());
        }
    };

    TEST_CLASS(Task1ExerciseTest)
    {
    public:
        TEST_METHOD(Task1_Constant)
        {
            auto generator = std::make_unique<miit::algebra::ConstantGenerator>(5);
            miit::algebra::Task1Exercise exercise(5, std::move(generator));
            exercise.execute();

            const miit::algebra::Matrix& result = exercise.get_matrix();

            for (size_t i = 0; i < result.size(); ++i)
            {
                Assert::AreEqual(5, result[i]);
            }
        }

        TEST_METHOD(Task1_EvenSize)
        {
            auto generator = std::make_unique<miit::algebra::ConstantGenerator>(1);
            miit::algebra::Task1Exercise exercise(4, std::move(generator));

            auto func = [&exercise]() { exercise.execute(); };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(Task1_Basic)
        {
            std::istringstream input("1 3 2 4 5");
            auto generator = std::make_unique<miit::algebra::IStreamGenerator>(input);
            miit::algebra::Task1Exercise exercise(5, std::move(generator));

            exercise.execute();
            const miit::algebra::Matrix& result = exercise.get_matrix();

            Assert::AreEqual(2, result[0]);
            Assert::AreEqual(3, result[1]);
            Assert::AreEqual(2, result[2]);
            Assert::AreEqual(4, result[3]);
            Assert::AreEqual(5, result[4]);
        }
    };

    TEST_CLASS(Task2ExerciseTest)
    {
    public:
        TEST_METHOD(ContainsDigitFive)
        {
            Assert::IsTrue(miit::algebra::Task2Exercise::contains_digit_five(5));
            Assert::IsTrue(miit::algebra::Task2Exercise::contains_digit_five(15));
            Assert::IsTrue(miit::algebra::Task2Exercise::contains_digit_five(51));
            Assert::IsTrue(miit::algebra::Task2Exercise::contains_digit_five(-50));
            Assert::IsFalse(miit::algebra::Task2Exercise::contains_digit_five(0));
            Assert::IsFalse(miit::algebra::Task2Exercise::contains_digit_five(123));
            Assert::IsFalse(miit::algebra::Task2Exercise::contains_digit_five(-46));
        }

        TEST_METHOD(Task2_Basic)
        {
            std::istringstream input("5 10 15 20 25 30");
            auto generator = std::make_unique<miit::algebra::IStreamGenerator>(input);
            miit::algebra::Task2Exercise exercise(6, std::move(generator));

            exercise.execute();
            const miit::algebra::Matrix& result = exercise.get_matrix();

            Assert::AreEqual(size_t(3), result.size());
            Assert::AreEqual(10, result[0]);
            Assert::AreEqual(20, result[1]);
            Assert::AreEqual(30, result[2]);
        }

        TEST_METHOD(Task2_Empty)
        {
            auto generator = std::make_unique<miit::algebra::ConstantGenerator>(5);
            miit::algebra::Task2Exercise exercise(3, std::move(generator));

            exercise.execute();
            const miit::algebra::Matrix& result = exercise.get_matrix();

            Assert::AreEqual(size_t(0), result.size());
        }
    };

    TEST_CLASS(Task3ExerciseTest)
    {
    public:
        TEST_METHOD(Task3_Basic)
        {
            std::istringstream input("1 2 3 4");
            auto generator = std::make_unique<miit::algebra::IStreamGenerator>(input);
            miit::algebra::Task3Exercise exercise(4, std::move(generator));

            exercise.execute();

            const miit::algebra::Matrix& matrix = exercise.get_matrix();

            Assert::AreEqual(1, matrix[0]);  
            Assert::AreEqual(4, matrix[1]);  
            Assert::AreEqual(9, matrix[2]);  
            Assert::AreEqual(8, matrix[3]);  
        }

        TEST_METHOD(Task3_Negatives)
        {
            std::istringstream input("-2 -3 4");
            auto generator = std::make_unique<miit::algebra::IStreamGenerator>(input);
            miit::algebra::Task3Exercise exercise(3, std::move(generator));

            exercise.execute();

            const miit::algebra::Matrix& matrix = exercise.get_matrix();

            Assert::AreEqual(4, matrix[0]);   
            Assert::AreEqual(-6, matrix[1]);  
            Assert::AreEqual(16, matrix[2]);  
        }
    };

    TEST_CLASS(ExerciseTest)
    {
    public:
        TEST_METHOD(ExerciseConstructorAndFill)
        {
            auto generator = std::make_unique<miit::algebra::ConstantGenerator>(7);
            miit::algebra::Task1Exercise exercise(3, std::move(generator));

            const miit::algebra::Matrix& matrix = exercise.get_matrix();
            Assert::AreEqual(size_t(3), matrix.size());
            Assert::AreEqual(7, matrix[0]);
            Assert::AreEqual(7, matrix[1]);
            Assert::AreEqual(7, matrix[2]);
        }

        TEST_METHOD(ExerciseGetMatrix)
        {
            auto generator = std::make_unique<miit::algebra::ConstantGenerator>(1);
            miit::algebra::Task1Exercise exercise(2, std::move(generator));

            const miit::algebra::Matrix& matrix1 = exercise.get_matrix();
            const miit::algebra::Matrix& matrix2 = exercise.get_matrix();

            Assert::IsTrue(&matrix1 == &matrix2);
        }
    };
}