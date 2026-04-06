// Задача на динамическое выделение памяти. Изначально есть указатель на массив с одним элементом. 
// Пользователь вводит число. Если оно больше 0 записываем его в массив. 
// Далее пользователь вводит второе число, тут уже,  если оно больше 0, 
// надо пере выделять память для 2-х элементов массива и записать в массив второе число. 
// И так далее…  для 3-х элементов, для 4-х…  пока пользователь не введет отрицательное число.

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	//setlocale(LC_ALL, "ru");

	int chislo = 1;
	int count = 1;
	int *massiv = new int[1];
	
	while (chislo > 0) {
		cout << "Введите целое число: ";
		cin >> chislo;
		if (chislo <= 0) { break; }

		if (count != 1) {
			int* temp = new int[count];
			for (int i = 0; i < count - 1; i++) {
				temp[i] = massiv[i];
			}
			//temp[count - 1] = chislo;
			delete[] massiv;
			massiv = temp;
		}

		massiv[count - 1] = chislo;
		count++;
	}

	for (int i = 0; i < count - 1; i++) {
		cout << massiv[i] << "\n";
	}
	cout << endl;

	return 0;
}