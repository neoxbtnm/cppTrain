// Программа должна сортировать массивы двумя способами. Заполнение массивов выполнять автоматически, 
// с помощью генератора случайных чисел rand. Каждый алгоритм сортировки оформить как отдельную функцию, 
// которая возвращает значение характеризуемое трудоемкость алгоритма (например, количество сравнений чисел или время, 
// которое было потрачено на сортировку). Выполнить сравнение алгоритмов на предмет эффективности.

//     1. Сортировка выбором. Сначала выполняется поиск  минимального элемента в массиве, после чего сохраняется во временную переменную. 
//     Затем этот элемент удаляется в массиве, а все последующие за ним элементы передвигаются на одну позицию влево. 
//     После этого сохраненный элемент заносится  в  последнюю позицию, которая освободилась после сдвига элементов влево.
    
//     2. Шейкер-сортировка. Движение в прямом и обратном направлениях организовать с помощью одного цикла.


#include <iostream>

using namespace std;


// Шаблон для узнавания размера массива
template <typename T, size_t n> int f(T (&a)[n])
{
  return n;
}


// 1 Алгоритм
template <typename T, size_t n> int firstSort(T (&mass)[n]) {
    int count = 0;
    int min_temp;
    int index;
    int prohod = 0;
    int len_arr = n;

    while (prohod < len_arr) {
        min_temp = mass[0];
        index = 0;

        for (int i = 0; i < len_arr - prohod; i++) {
            if (min_temp > mass[i]) {
                min_temp = mass[i];
                index = i;
            }
            count++;
        }
        for (int i = index + 1; i < len_arr; i++) {
            mass[i-1] = mass[i];
        }
        mass[len_arr - 1] = min_temp;
        prohod++;
    }

    cout << "\n\n\n";
    for (int i = 0; i < len_arr; i++) {
        cout << i << " " << mass[i] << "\n";
    }
    return count;
}

// 2 Алгоритм
template <typename T, size_t n> int secondSort(T (&mass)[n]) {
    int len_arr = n;
    int min_element = mass[0];
    int min_index = 0;
    int max_element = mass[0];
    int max_index = 0;

    int prohod = 0;
    int i = 0;
    int count = 0;
    while (prohod < len_arr) {
        if (mass[i] > max_element) {
            max_element = mass[i];
            max_index = i;
            count++;
        } else if (mass[i] < min_element) {
            min_element = mass[i];
            min_index = i;
            count += 2;
        } else {
            count += 2;
        }

        if ((prohod/2 == prohod/2 + prohod%4) | prohod == 0) {
            i++;
            if (i == len_arr - 1 - prohod/2) {
                mass[min_index] = mass[i];
                mass[i] = min_element;
                mass[max_index] = mass[prohod/2];
                mass[prohod/2] = max_element;
                min_element = mass[i - 1];
                min_index = i - 1;

                min_element = mass[i - 1];
                min_index = i - 1;
                max_element = mass[i - 1];
                max_index = i - 1;

                prohod += 2;
                i--;
            }

        } else {
            i--;
            if (i == prohod/2) {
                mass[min_index] = mass[len_arr - 1 - prohod/2];
                mass[len_arr - 1 - prohod/2] = min_element;
                mass[max_index] = mass[i];
                mass[i] = max_element;

                min_element = mass[i + 1];
                min_index = i + 1;
                max_element = mass[i + 1];
                max_index = i + 1;

                prohod += 2;
                i++;
            }
        }
    }
    cout << "\n";
    for (int i = 0; i < len_arr; i++) {
        cout << i << " " << mass[i] << endl;
    }

    return count;
}


int main() {
    static int arr_1[100];

    for (int i = 0; i < 100; i++) {
        arr_1[i] = rand();
    }

    int arr_2[100];
    for (int i = 0; i < 100; i++) {
        cout << i << " " << arr_1[i] << "\n";
        arr_2[i] = arr_1[i];
    }
    
    int count_1 = firstSort(arr_1);
    int count_2 = secondSort(arr_2);

    cout << "\n\n\n" << count_1;
    cout << "\n\n\n" << count_2;

    return 0;
}