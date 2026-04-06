//Начальное приближение y0 = x.
//Итерации прекратить при | yi + 1 - yi | < 10 - 5. 
//Смысл данного задания — найти корень кубический без использования специальных функций.
//Задание не сложное, но интересное, результат работы программы показан ниже :

#include <cstdlib>
#include <iostream>

using namespace::std;

int main() {
	int x = 0;

	cout << "Введите x: ";
	cin >> x;

	if (x == 0) {
		return 1;
	}

	float y = x; // начальное значение y
	float yi1;

	int count = 0;
	do {
		yi1 = y;
		y = 0.5 * (y + 3 * x / (2 * y * y + x / y));
		cout << "\n prohod" << count << " " << y << " - " << yi1;
		count++;
	} while ((yi1 - y) > 1 / 100000);
	cout << "\n" << yi1;

	return 0;
}

