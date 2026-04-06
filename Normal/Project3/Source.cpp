//Нужно вычислить произведение матрицы на вектор.В полученном векторе найти макисмальный  элемент.необходимо решить данную задачу тремя способами :
//1) с использованием статических массивов
//2) использовать только динамические массивы с явным разыменованием указателя
//3) использовать только динамические массивы, адресацию к элементам массива выполнять с помощью индексов.

#include <iostream>

using namespace std;

int main()
{
	int count_stolb, count_strok;
	cout << "Количество строк матрицы: "; cin >> count_strok;
	cout << "Количество столбцов матрицы: "; cin >> count_stolb;

	const int strok_matrix = count_strok, stolb_matrix = count_stolb;
	count_stolb = 0, count_strok = 0;
	int matrix[][];


	for (count_stolb != stolb_matrix; count_stolb++)
	{
		for (count_strok != strok_matrix; count_strok++)
		{
			cout << "matrix[" << count_stolb + 1 << "][" << count_strok + 1 << "]: "; cin >> matrix[count_stolb][count_strok];
		}
	}
}