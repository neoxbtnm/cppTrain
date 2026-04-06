// 1. Определение длинны строки, функция должна возвращать количество символов входной строки.
// 2. Определение длинны строки, функция должна возвращать количество символов входной строки.
// 3. Функция для проверки баланса скобок, то есть количество открытых скобок должно совпадать 
// с количеством закрытых, причём необходимо отличать тип скобочек — круглые, квадратные, фигурные. 
// Функция возвращает значение типа int, если 0 — баланс скобок нарушен, если 1 — баланс скобок выдержан,
//  если -1 скобок во входной строке нет.
// 4. Функция должна возвращать номер позиции. начиная с которой подстрока входит в строку.
// 5. Функция конкатенации строк, но конкатенация выполняется начиная с n-й позиции так, 
// что вторая строка вставляется в первую строку не удалив ни одного из символов первой строки. 
// Возвращаемое значение — строка, полученная после вставки второй в первую строки. Пример:
// входные данные: строка 1 — cpp.com, строка 2 — studio, номер позиции = 4
// результат = cppstudio.com
// 6. Функция должна скопировать часть входной строки (k символов), начиная с позиции с номером N.

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>


using namespace::std;

// 1
int len_string(char* str_ish) {
    int i;
    for (i = 0; (int) str_ish[i] != 0; i++) {
        //cout << i << " " << (int) str_ish[i] << " " << str_ish[i] << '\n';
    }
    return i;
}

// 2
char* revString(char * str_ish) {
    int len_str = len_string(str_ish);
    char* str_temp = (char*)malloc(sizeof(char) * len_str);
    for (int i = 0; i < len_str; i++) {
        str_temp[len_str - 1 - i] = str_ish[i];
    }
    return str_temp;
}

// 3
int balanceSkobok(char* str_ish) {
    int len_str = len_string(str_ish);
    int sc_1_a = 0, sc_1_b = 0, sc_2_a = 0, sc_2_b = 0, sc_3_a = 0, sc_3_b = 0;

    for (int i = 0; i < len_str; i++) {
        if (str_ish[i] == '(') {sc_1_a++;} 
        else if (str_ish[i] == ')') {sc_1_b++;}
        else if (str_ish[i] == '{') {sc_2_a++;}
        else if (str_ish[i] == '}') {sc_2_b++;}
        else if (str_ish[i] == '[') {sc_3_a++;}
        else if (str_ish[i] == ']') {sc_3_b++;}
    }

    if (sc_1_a + sc_1_b + sc_2_a + sc_2_b + sc_3_a + sc_3_b == 0) {
        return -1;
    }
    if (sc_1_a == sc_1_b || sc_2_a == sc_2_b || sc_3_a == sc_3_b) {
        return 1;
    } else {
        return 0;
    }
}

// 4
int occurSubstr(char* str_1, char* str_2) {
    int len_str_1 = len_string(str_1);
    int len_str_2 = len_string(str_2);
    for (int i = 0; i < len_str_2; i++) {
        int ii = i;
        for (int j = 0; j < len_str_1; j++) {
            if (str_2[ii] != str_1[j]) {
                break;
            }
            if (j == len_str_1 - 1) {
                i++;
                return i;
            }
            ii++;
        }
    }

    return -1;
}

// 5
char* insertString(char* str_1, char* str_2, int index_func) {
    int lenstr_1 = len_string(str_1);
    int lenstr_2 = len_string(str_2);
    char* itog_string = (char*)malloc(sizeof(char) * (lenstr_1 + lenstr_2));
    for (int i = 0; i < (lenstr_1 + lenstr_2 + 1); i++) {
        if (i == index_func - 1) {
            for (int j = 0; j < lenstr_2; j++) {
                itog_string[i] = str_2[j];
                i++;
            }
        } else if (i < index_func - 1) {
            itog_string[i] = str_1[i];
        } else {
            itog_string[i] = str_1[i - lenstr_2 - 1];
        }
    }
    return itog_string;
}

// 6
char* cutString(char* str_1, int index_num, int len_num) {
    char* str_2 = (char*)malloc(sizeof(char) * len_num);
    int lenstr_1 = len_string(str_1);
    int j = 0;
    for (int i = index_num - 1; i < (index_num + len_num - 1); i++) {
        str_2[j] = str_1[i];
        j++;
    }

    return str_2;
}



int main() {
    string str_ish;
    cout << "Введите строку: ";
    getline(cin, str_ish);
    
    char* char_ish = str_ish.data();
    cout << "\n" << char_ish << endl;
    
    // 1
    int lenstr = len_string(char_ish);
    cout << "Длина строки: " << lenstr << endl;

    // 2
    char* revStr = revString(char_ish);
    cout << "Конвертированная строка: " << revStr << endl; 

    // 3
    int balance_sc = balanceSkobok(char_ish);
    if (balance_sc == -1) {cout << "Скобок во входной строке нет" << endl;}
    else if (balance_sc == 0) {cout << "Баланс скобок нарушен" << endl;}
    else {cout << "Баланс скобок выдержан" << endl;}

    // 4
    char* char_4_func_primer = "cppstudio.com";
    string str_4_func;
    cout << "Введите строку для получения позиции подстроки: " << char_4_func_primer << "\nВведите строку: ";
    getline(cin, str_4_func);
    char* char_4_func = str_4_func.data();
    int occursubstr = occurSubstr(char_4_func, char_4_func_primer);
    if (occursubstr == -1) {
        cout << "\nПодстроки не существует" << endl;
    } else {
        cout << "\nНомер позиции = " << occursubstr << endl;
    }

    // 5
    char* char_5_func_primer = "cpp.com";
    string str_5_func;
    cout << "Первая строка для конкатенации: " << char_5_func_primer << "\nВведите вторую строку для конкатенации: ";
    getline(cin, str_5_func);
    char* char_5_func = str_5_func.data();
    cout << "\nВведите индекс: ";
    int num_index;
    cin >> num_index;
    char* insertstr = insertString(char_5_func_primer, char_5_func, num_index);
    cout << "Результат объединения = " << insertstr << endl;

    // 6
    int num_func_6, num_len_func_6;
    cout << "\nВведите строку из которой необходимо скопировать n символов: " << char_4_func_primer;
    cout << "\nВведите длину копируемой строки: ";
    cin >> num_len_func_6;
    cout << "Введите номер позиции, начиная с которой необходимо скопировать строку: ";
    cin >> num_func_6;
    char* cutstr = cutString(char_4_func_primer, num_func_6, num_len_func_6);
    cout << "\nСкопированная строка: " << cutstr << endl;


    return 0;
}