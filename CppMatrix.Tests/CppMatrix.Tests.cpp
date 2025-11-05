#include "CppUnitTest.h"
#include "Matrix.h"
#include "RandomGenerator.h"
#include "ConstantGenerator.h"
#include "TaskExercise.h"
#include <stdexcept>
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
        TEST_METHOD(ShiftLeftOperatort)
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

        TEST_METHOD(Min)
        {
            miit::algebra::Matrix matrix{ 5, 2, 8, 1, 4 };
            Assert::AreEqual(1, matrix.min());
        }

        TEST_METHOD(Middle)
        {
            miit::algebra::Matrix matrix{ 1, 2, 3, 4, 5 };
            Assert::AreEqual(3, matrix.middle());
        }

        TEST_METHOD(Middle_EvenSize)
        {
            miit::algebra::Matrix matrix{ 1, 2, 3, 4 };

            auto func = [&matrix]() { matrix.middle(); };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(Average)
        {
            miit::algebra::Matrix matrix{ 1, 2, 3, 4, 5 };
            double avg = matrix.average();

            Assert::AreEqual(3.0, avg, 0.001);
        }

        TEST_METHOD(ContainsDigitFive_DetectsCorrectly)
        {
            Assert::IsTrue(miit::algebra::Matrix::contains_digit_five(5));
            Assert::IsTrue(miit::algebra::Matrix::contains_digit_five(15));
            Assert::IsTrue(miit::algebra::Matrix::contains_digit_five(51));
            Assert::IsTrue(miit::algebra::Matrix::contains_digit_five(-50));
            Assert::IsFalse(miit::algebra::Matrix::contains_digit_five(0));
            Assert::IsFalse(miit::algebra::Matrix::contains_digit_five(123));
            Assert::IsFalse(miit::algebra::Matrix::contains_digit_five(-46));
        }

        TEST_METHOD(RemoveElementsWithDigitFive)
        {
            miit::algebra::Matrix matrix{ 5, 10, 15, 20, 25, 30 };
            matrix.remove_elements_with_digit_five();

            Assert::AreEqual(std::string("[10, 20, 30]"), matrix.to_string());
        }

        TEST_METHOD(TransformByRule)
        {
            miit::algebra::Matrix matrix{ 1, 2, 3, 4 };
            miit::algebra::Matrix result = matrix.transform_by_rule();

            Assert::AreEqual(1, result[0]);  // |1^2| = 1
            Assert::AreEqual(4, result[1]);  // 2*2 = 4
            Assert::AreEqual(9, result[2]);  // |3^2| = 9
            Assert::AreEqual(8, result[3]);  // 2*4 = 8
        }
    };

    TEST_CLASS(GeneratorTest)
    {
    public:
        TEST_METHOD(RandomGenerator_GeneratesInRange)
        {
            miit::algebra::RandomGenerator generator(-100, 100);
            int value = generator.generate();

            Assert::IsTrue(value >= -100 && value <= 100);
        }

        TEST_METHOD(ConstantGenerator_AlwaysReturnsSameValue)
        {
            miit::algebra::ConstantGenerator generator(42);

            Assert::AreEqual(42, generator.generate());
            Assert::AreEqual(42, generator.generate());
            Assert::AreEqual(42, generator.generate());
        }

        TEST_METHOD(IStreamGenerator_ReadsFromStream)
        {
            std::istringstream input("10 20 30");
            miit::algebra::IStreamGenerator generator(input);

            Assert::AreEqual(10, generator.generate());
            Assert::AreEqual(20, generator.generate());
            Assert::AreEqual(30, generator.generate());
        }
    };

    TEST_CLASS(TaskExerciseTest)
    {
    public:
        TEST_METHOD(Task1_ReplacesMinWithMiddle)
        {
            auto generator = std::make_unique<miit::algebra::ConstantGenerator>(5);
            miit::algebra::TaskExercise exercise(5, std::move(generator));
            exercise.fill_matrix();

            exercise.Task1();
            const miit::algebra::Matrix& result = exercise.get_matrix();

            for (size_t i = 0; i < result.size(); ++i)
            {
                Assert::AreEqual(5, result[i]);
            }
        }

        TEST_METHOD(Task1EvenSize)
        {
            auto generator = std::make_unique<miit::algebra::ConstantGenerator>(1);
            miit::algebra::TaskExercise exercise(4, std::move(generator));
            exercise.fill_matrix();

            auto func = [&exercise]() { exercise.Task1(); };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(Task2)
        {
            miit::algebra::Matrix matrix{ 5, 10, 15, 20, 25 };
            auto generator = std::make_unique<miit::algebra::ConstantGenerator>(1);
            miit::algebra::TaskExercise exercise(5, std::move(generator));

            miit::algebra::Matrix test_matrix = matrix;
            test_matrix.remove_elements_with_digit_five();

            Assert::AreEqual(size_t(2), test_matrix.size());
            Assert::AreEqual(10, test_matrix[0]);
            Assert::AreEqual(20, test_matrix[1]);
        }

        TEST_METHOD(Task3)
        {
            miit::algebra::Matrix matrix{ 1, 2, 3, 4 };
            miit::algebra::Matrix result = matrix.transform_by_rule();

            Assert::AreEqual(1, result[0]);  // |1^2| = 1
            Assert::AreEqual(4, result[1]);  // 2*2 = 4
            Assert::AreEqual(9, result[2]);  // |3^2| = 9
            Assert::AreEqual(8, result[3]);  // 2*4 = 8
        }
    };
}