// Составить программу, которая будет генерировать случайные числа в интервале [a;b] и заполнять ими двумерный массив размером 10 на 10. 
// В массиве необходимо найти номер строки с минимальным элементом. Поменять строки массива местами, строку с минимальным элементом 
// и первую строку массива. Организовать удобный вывод на экран.

#include <iostream>
#include <cstdlib>

using namespace::std;

int main(){
    //srand(time(NULL));
    int a_min, a_max;
    cout << "Введите число min: ";
    cin >> a_min;
    cout << "Введите число max: ";
    cin >> a_max;
    a_min = a_min * 1000;
    a_max = a_max * 1000 - a_min;


    float** arr = (float**)malloc(sizeof(float*) * 10);
    for (int i = 0; i < 10; i++) {
        arr[i] = (float*)malloc(sizeof(float) * 10);
    }

    float last_elem;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            srand(last_elem);
            float a = a_min + rand() % a_max;
            last_elem = a_min + rand() % a_max;
            a = a / 1000;
            arr[i][j] = a;
        }
        //cout << a << endl;
        //cout << endl;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    float min_element = arr[0][0];
    int min_string = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] < min_element) {
                min_element = arr[i][j];
                min_string = i;
            }
        }
    }

    cout << "\nНомер строки с минимальным элементом: " << min_string + 1 << endl;
    cout << "Минимальный элемент: " << min_element << endl;

    cout << "\n\nМассив с переустановленными строками\n";
    if (min_string != 0) {
        float* arr2 = (float*)malloc(sizeof(float) * 10);
        for (int j = 0; j < 10; j++) {
            arr2[j] = arr[0][j];
            arr[0][j] = arr[min_string][j];
            arr[min_string][j] = arr2[j];
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    //return 0;
}