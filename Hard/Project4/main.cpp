// Дана квадратная матрица размером nxn. Найти минимальный элемент среди элементов, 
// расположенных ниже главной диагонали, найти максимальный элемент, среди элементов 
// расположенных выше побочной диагонали. Найденные минимальный и максимальный элементы 
// поменять местами и вывести их индексы.

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int num_x;
    cout << "Введите размер квадратной матрицы: ";
    cin >> num_x;

    int** arr = (int**)malloc(sizeof(int*) * num_x);
    for (int i = 0; i < num_x; i++) {
        arr[i] = (int*)malloc(sizeof(int) * num_x);
        for (int j = 0; j < num_x; j++) {
            arr[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < num_x; i++) {
        for (int j = 0; j < num_x; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    int start_x = 0;
    int start_y = 1;

    int min_osn = arr[1][0];
    int min_osn_index[] = {1, 0};
    for (int j = start_x; j < num_x; j++) {
        cout << "\n";
        for (int i = start_y; i < num_x; i++) {
            cout << arr[i][j] << " ";
            if (arr[i][j] < min_osn) {
                min_osn = arr[i][j];
                min_osn_index[0] = i;
                min_osn_index[1] = j;
            }
        }
        start_x++;
        start_y++;
    }

    start_y = 0;

    int max_vspom = arr[0][1];
    int max_vspom_index[] = {0, 1};
    for (int i = start_y; i < num_x; i++) {
        start_x--;
        cout << "\n";
        for (int j = 0; j < start_x; j++) {
            cout << arr[i][j] << " ";
            if (arr[i][j] > max_vspom) {
                max_vspom = arr[i][j];
                max_vspom_index[0] = i;
                max_vspom_index[1] = j;
            }
        }
        start_y++;
    }

    cout << "\nmin[" << min_osn_index[0] << "][" << min_osn_index[1] << "] = " << min_osn;
    cout << "\nmax[" << max_vspom_index[0] << "][" << max_vspom_index[1] << "] = " << max_vspom << endl;

    arr[max_vspom_index[0]][max_vspom_index[1]] = min_osn;
    arr[min_osn_index[0]][min_osn_index[1]] = max_vspom;

    cout << "\n Массив после перестановки максимального и минимального элементов:\n";
    for (int i = 0; i < num_x; i++) {
        for (int j = 0; j < num_x; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}