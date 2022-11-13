#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_4_Iter/Lab_06_4_Iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int TestMin(int* a, const int size)
{
	int min = abs(a[0]), imin = 0;
	for (int i = 1; i < size; i++)
		if (abs(a[i]) < min)
		{
			min = a[i];
			imin = i;
		}
	return imin;
}

int TestSum(int* a, const int size)
{
	int n = 0;
	for (int i = 0; i < size; i++)
		if (a[i] < 0)
		{
			for (int j = i + 1; j < size; j++)
				n += abs(a[j]);
			break;
		}
	return n;
}

int* TestCompress(int* a, const int size, int b, int c)
{
	int i = 0;
	while (i < size)
	{
		if (a[i] >= b && a[i] <= c)
			for (int j = i; j < size - 1; j++)
			{
				a[j] = a[j + 1];
				a[j + 1] = 0;
			}
		else
			i++;
	}
	return a;
}

void Test(int* a, const int size, int b, int c)
{
	Assert::AreEqual(TestMin(a, size), Min(a, size));
	Assert::AreEqual(TestSum(a, size), Sum(a, size));
	int* n = a;
	a = (TestCompress(a, size, b, c));
	n = (Compress(n, size, b, c));
	for (int i = 0; i < size; i++)
		Assert::AreEqual(a[i], n[i]);
}

namespace UnitTestLab064Iter
{
	TEST_CLASS(UnitTestLab064Iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 10;
			int c[n];
			int Low = -10, High = 10, a = 5, b = 10;
			Create(c, n, Low, High);
			Test(c, n, a, b);
		}
	};
}