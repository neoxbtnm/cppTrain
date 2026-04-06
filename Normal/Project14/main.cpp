/* Создать класс, описывающий понятие работник, со свойствами:

фамилия;
стаж;
часовая заработная плата;
количество отработанных часов.
*/

#include <iostream>
#include <string>
#include "Worker.h"
#include <fcntl.h>
#include <io.h>


int wmain() {
	_setmode(_fileno(stdin), _O_U16TEXT); // фикс utf-16 для консоли in
	_setmode(_fileno(stdout), _O_U16TEXT); // out
	

	std::wstring name;
	float exp;
	float moneyrate;
	int hours;

	std::wcout << L"Введите имя работника: ";
	std::getline(std::wcin, name);
	std::wcout << L"Введите стаж работника: ";
	std::wcin >> exp;
	std::wcout << L"Введите зарплату работника: ";
	std::wcin >> moneyrate;
	std::wcout << L"Введите сколько работник " << name << L" отработал часов: ";
	std::wcin >> hours;

	Worker abobus1(name, exp, moneyrate, hours);

	abobus1.print_info();
	abobus1.print_to_file();
}