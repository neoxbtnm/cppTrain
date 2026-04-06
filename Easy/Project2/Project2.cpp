// Найти алгебраическую сумму для выражения: 1^k + 2^k + 3^k + … + N^k.
// N и степень k вводит пользователь.

#include <iostream>

int main() {
	setlocale(LC_ALL, "");

	int n, k, sum = 0;
	std::wcout << L"Введите N: ";
	std::cin >> n;
	std::wcout << L"Введите степень k: ";
	std::cin >> k;

	for (int count = 1; count <= n; count++) {
		sum += pow(count, k);
	}

	std::wcout << L"Сумма: " << sum;
}