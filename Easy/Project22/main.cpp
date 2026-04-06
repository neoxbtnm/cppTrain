// Найти след матрицы,  след матрицы — сумма элементов главной диагонали. 
// Размер матрицы вводит пользователь, матрицу заполнять случайными числами.


#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
	setlocale(LC_ALL, "");
	std::srand(std::time(0));

	std::vector <std::vector <int>> vMatrix; // Создание двумерного вектора для матрицы

	int iStr, iColumn; //
	std::wcout << L"Введите количество строк матрицы: ";
	std::cin >> iStr;
	std::wcout << L"Введите количество столбцов матрицы: ";
	std::cin >> iColumn;
	
	for (int i = 0; i < iStr; i++) {
		std::vector <int> vStrings;
		vStrings.resize(iColumn);
		for (int n = 0; n < iColumn; n++) {
			vStrings[n] = rand();
		}
		vMatrix.push_back(vStrings);
	}

	int aSled = 0;
	for (int i = 0; i < iStr; i++) {
		for (int n = 0; n < iColumn; n++) {
			if (i == n) {
				std::cout << "\033[31m" << vMatrix[i][n] << " \033[0m";
			}
			else {
				std::cout << vMatrix[i][n] << " ";
			}
		}
		std::cout << std::endl;

		aSled += vMatrix[i][i];
	}

	std::wcout << L"След матрицы: " << aSled;
}