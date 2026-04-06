#pragma once
#include <fstream>


class Worker {
private:
	std::wstring worker_name;
	float worker_exp;
	float worker_money_rate;
	int worker_hours;

public:
	Worker(const std::wstring& name, float exp, float hourMoney, int hours)
		: worker_name(name), worker_exp(exp), worker_money_rate(hourMoney), worker_hours(hours) {
	}

	const std::wstring& get_name() const {
		return worker_name;
	}

	const float get_exp() const {
		return worker_exp;
	}

	const float get_hmr() const {
		return worker_money_rate;
	}

	const int get_hours() const {
		return worker_hours;
	}

	double get_prem() const {
		double premy = get_zp();

		if (worker_exp < 1) return 0;
		if (worker_exp < 3) return premy * 0.05;
		if (worker_exp <= 5) return premy * 0.08;
		return premy * 0.15;
	}

	double get_zp() const {
		return worker_money_rate * worker_hours;
	}

	void print_info() const {
		std::wcout << get_name() << L"\n";
		std::wcout << L"Experience is " << get_exp() << L"\n";
		std::wcout << L"Hourly wage is " << get_hmr() << L"\n";
		std::wcout << get_name() << L" has worked " << get_hours() << L" hours" << L"\n";
		std::wcout << L"Salary is " << get_zp() << L"\n";
		std::wcout << L"Premy is " << get_prem() << L"\n";
	}

	void print_to_file() const {
		std::wofstream file("worker.txt");
		file.imbue(std::locale("")); // Фикс локали для записи кириллицы в файл

		if (file.is_open()) {
			file << get_name() << std::endl;
			file << L"Experience is " << get_exp() << L"\n";
			file << L"Hourly wage is " << get_hmr() << L"\n";
			file << get_name() << L" has worked " << get_hours() << L" hours" << L"\n";
			file << L"Salary is " << get_zp() << L"\n";
			file << L"Premy is " << get_prem();
			std::wcout << L"file is written!";
		}
		else {
			std::cerr << "Ошибка открытия файла!" << "\n";
		}
	}
};