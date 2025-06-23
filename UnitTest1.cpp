// В файле UnitTest1.cpp тестового проекта
#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Задания не весну\ИЗ мирко 2\ИЗ мирко 2\ИЗ мирко 2.cpp"  // Путь к вашему заголовочному файлу

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryCompressorTests
{
    TEST_CLASS(GroupToLetterTests)
    {
    public:
        TEST_METHOD(ValidZeroCount)
        {
            // Проверка корректных значений
            Assert::AreEqual('a', groupToLetter(0));
            Assert::AreEqual('b', groupToLetter(1));
            Assert::AreEqual('c', groupToLetter(2));
            Assert::AreEqual('d', groupToLetter(3));
            Assert::AreEqual('y', groupToLetter(24));
            Assert::AreEqual('z', groupToLetter(25));
        }

        TEST_METHOD(InvalidZeroCount_Negative)
        {
            // Проверка отрицательного значения
            auto func = [] { groupToLetter(-1); };
            Assert::ExpectException<std::out_of_range>(func);
        }

        TEST_METHOD(InvalidZeroCount_TooLarge)
        {
            // Проверка значения больше 25
            auto func = [] { groupToLetter(26); };
            Assert::ExpectException<std::out_of_range>(func);
        }
    };

    TEST_CLASS(CompressFunctionTests)
    {
    public:
        TEST_METHOD(SingleGroup)
        {
            // Проверка одиночных групп
            Assert::AreEqual(std::string("a"), compress("1"));
            Assert::AreEqual(std::string("b"), compress("01"));
            Assert::AreEqual(std::string("c"), compress("001"));
            
        }

        TEST_METHOD(MultipleGroups)
        {
            // Проверка нескольких групп
            Assert::AreEqual(std::string("ab"), compress("101"));
            Assert::AreEqual(std::string("abc"), compress("101001"));
            Assert::AreEqual(std::string("ac"), compress("1001"));
           
        }

        TEST_METHOD(EdgeCases)
        {
            // Граничные случаи
            Assert::AreEqual(std::string("a"), compress("1"));               // Минимальная длина
            Assert::AreEqual(std::string("z"), compress("00000000000000000000000001")); // Максимальная группа
        }

        TEST_METHOD(InvalidInput_NoOne)
        {
            // Нет завершающей единицы
            auto func = [] { compress("000"); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(InvalidInput_WrongSymbol)
        {
            // Недопустимый символ
            auto func = [] { compress("10x1"); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

       
    };
}