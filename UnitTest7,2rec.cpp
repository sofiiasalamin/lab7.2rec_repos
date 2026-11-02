#include "pch.h"
#include "CppUnitTest.h"
#include "../7,2rec/7,2rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


static int** MakeMatrix(const int n, const int m, const int* v)
{
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
		for (int j = 0; j < m; j++)
			a[i][j] = v[i * m + j];
	}
	return a;
}

static void DeleteMatrix(int** a, const int n)
{
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
}

namespace UnitTestRec
{
	TEST_CLASS(UnitTestRec)
	{
	public:

		TEST_METHOD(SumAntiDiagonal_OneElement_ReturnsElement)
		{
			int v[1] = { 7 };
			int** a = MakeMatrix(1, 1, v);
			Assert::AreEqual(7, SumAntiDiagonal(a, 1, 1, 0));
			DeleteMatrix(a, 1);
		}

		

		

		TEST_METHOD(SumAntiDiagonal_ZeroMatrix_ReturnsZero)
		{
			int v[4] = { 0, 0, 0, 0 };
			int** a = MakeMatrix(2, 2, v);
			Assert::AreEqual(0, SumAntiDiagonal(a, 2, 2, 0));
			DeleteMatrix(a, 2);
		}

		

		

		TEST_METHOD(Create_ValuesInRange)
		{
			const int n = 5, m = 6, Low = -7, High = 65;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
			{
				a[i] = new int[m];
				for (int j = 0; j < m; j++)
					a[i][j] = 1000;                     
			}
			CreateRows(a, n, m, Low, High, 0);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					Assert::IsTrue(a[i][j] >= Low);
					Assert::IsTrue(a[i][j] <= High);
				}
			DeleteMatrix(a, n);
		}
	};
}