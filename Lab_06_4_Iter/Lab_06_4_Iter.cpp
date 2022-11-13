#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size)
{
	cout << "Значення таблиці : ";
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}

int Min(int* a, const int size)
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

int Sum(int* a, const int size)
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

const int N(int* a, const int size, int b, int c)
{
	int k = 0;
	for (int i = 0; i < size; i++)
		if (a[i] >= b && a[i] <= c)
			k++;
	const int n = size - k;
	return n;
}

int* Compress(int* a, const int size, int b, int c)
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

int main()
{
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));

	int n, Low, High, a, b;

	cout << "n = "; cin >> n;
	cout << "min = "; cin >> Low;
	cout << "max = "; cin >> High;
	cout << "a = "; cin >> a;	
	cout << "b = "; cin >> b;

	int* c = new int[n];

	Create(c, n, Low, High);
	Print(c, n);
	cout << "imin = " << Min(c, n) << endl;
	cout << "Sum = " << Sum(c, n) << endl;
	Print(Compress(c, n, a, b), N(c, n, a, b));

	return 0;
}