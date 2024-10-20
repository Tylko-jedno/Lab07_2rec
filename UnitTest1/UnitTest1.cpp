#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../Lab07_2rec/Lab07_2rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

int** CreateArray(const int rowCount, const int colCount) {
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];
    return a;
}

void DeleteArray(int** a, const int rowCount) {
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
}

namespace ArrayTest
{
    TEST_CLASS(ArrayTest)
    {
    public:

        TEST_METHOD(CreateTest)
        {
            int rowCount = 3, colCount = 4;
            int** a = CreateArray(rowCount, colCount);
            Create(a, rowCount, colCount, 1, 10, 0, 0);

            for (int i = 0; i < rowCount; i++) {
                for (int j = 0; j < colCount; j++) {
                    Assert::IsTrue(a[i][j] >= 1 && a[i][j] <= 10);
                }
            }

            DeleteArray(a, rowCount);
        }
        TEST_METHOD(TestSearchMaxSum)
        {
            const int k = 2;
            const int n = 4;
            int** a = new int* [k];
            a[0] = new int[n] { -1, -2, -3, 4 };
            a[1] = new int[n] { 5, -6, -7, 8 };

            int result = SearchMaxSum(a, k, n, 0, 0, 0, a[0][0]);
            Assert::AreEqual(12, result);

            for (int i = 0; i < k; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}
