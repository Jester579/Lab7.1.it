#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.1it/Source.cpp"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(Test_Calc)
        {
            int rowCount = 2, colCount = 3;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            a[0][0] = 1;
            a[0][1] = 3;
            a[0][2] = 4;
            a[1][0] = -2;
            a[1][1] = 5;
            a[1][2] = -7;

            int S, k;

            Calc(a, rowCount, colCount, S, k);

            int result((S == 9 && k == 3)? 1 : 0);

            Assert::AreEqual(result, 1);

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}
