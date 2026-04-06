//Программа должна выполнять преобразования строки(длина строки 255 символов) :
//
//    СТРОКА ЗАГЛАВНЫМИ БУКВАМИ
//    строка в нижнем регистре
//    С Заглавной Буквы(Первый Символ Каждого Слова В Строке)
//    пЕРВЫЙ сИМВОЛ в нИЖНЕМ рЕГИСТРЕ
//    Как в предложении(с заглавной буквы).
//    Символ 'f' — выход из программы
//
//    Организовать в программе меню, через которое можно удобно выбирать любое действие.Программа должна выполняться пока пользователь не введет  символ 'f'.


#include <iostream>
#include <cctype>
#include <string>

using namespace::std;

int main() {
	string string_1;
	string string_2;
	char input_int;


	cout << "Введите строку\n" << endl;
	getline(cin, string_1);
	string_2 = string_1;
	cout << string_1 << "\n" << endl;

	cout << "Для преобразования строки в заглавные буквы нажмите : 1\n"
		<< "Для преобразования строки в нижний регистр нажмите : 2\n"
		<< "Для преобразования строки с заглавной буквы нажмите : 3\n"
		<< "Для преобразования строки в первый символ в нижнем регистре нажмите : 4\n"
		<< "Для преобразования строки как в обычном предложении нажмите : 5\n"
		<< "Для выхода нажмите : f\n" << endl;

	
	while (' ' == ' ') {
		cout << "Введите необходимое действие : ";
		cin >> input_int;

		int i = 0;

		switch (input_int) {
		case '1':
			while (string_1[i]) {
				string_2[i] = (char)toupper(string_1[i]);
				i++;
			}
			i = 0;
			break;
		case '2':
			while (string_1[i]) {
				string_2[i] = (char)tolower(string_1[i]);
				i++;
			}
			i = 0;
			break;
		case '3':
			if (i == 0) {
				string_2[i] = (char)toupper(string_1[i]);
				i++;
			}
			while (string_1[i]) {
				if (string_1[i - 1] == ' ') {
					string_2[i] = (char)toupper(string_1[i]);
				}
				i++;
			}
			i = 0;
			break;
		case '4':
			if (i == 0) {
				string_2[i] = (char)tolower(string_1[i]);
				i++;
			}
			while (string_1[i]) {
				if (string_1[i - 1] == ' ') {
					string_2[i] = (char)tolower(string_1[i]);
				}
				else {
					string_2[i] = (char)toupper(string_1[i]);
				}
				i++;
			}
			i = 0;
			break;
		case '5':
			while (string_1[i]) {
				if (i == 0) {
					string_2[i] = (char)toupper(string_1[i]);
				}
				else {
					string_2[i] = (char)tolower(string_1[i]);
				}
				i++;
			}
			i = 0;
			break;
		case 'f':
			return 0;
		}
		cout << string_2 << "\n";
	}
}