// Найти Y, если Y = X1 + X2 + … + Xn,   X = Z^3 - B + A^2 / tg^2?. 
// Количество X вводятся пользователем программы. 
// Для каждого X значения Z, B, А, ? разные (вводятся пользователем программы).

#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	setlocale(LC_ALL, ""); // Для кириллицы

	int x_count;
	double y = 0;
	

	std::wcout << L"Введите количество X:\n";
	std::cin >> x_count;


	for (int count = 0; count < x_count; count++) { // Запись данных для вычасления
		double z, b, a, betta;
		std::wcout << L"Введите Z, B, A, Betta для X" << count + 1 << ":" << std::endl;
		std::cout << "Z: ";
		std::cin >> z;
		std::cout << "B: ";
		std::cin >> b;
		std::cout << "A: ";
		std::cin >> a;
		std::cout << "Betta: ";
		std::cin >> betta;

		y = y + std::pow(z, 3) - b + std::pow(a, 2) / std::pow(tan(betta), 2);
	}

	std::cout << "Y = " << y;
	return 0;
}