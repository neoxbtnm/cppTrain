/* Требуется написать программу, которая заполняет массив размерности nxn по заданному правилу:
      1  3  4 10 11
      2  5  9 12 19
      6  8 13 18 20
      7 14 17 21 24
     15 16 22 23 25 
*/

#include <iostream>
#include <iomanip>

using namespace::std;


int main() {
    int x;
    int count = 1;
    cout << "Введите число: "; cin >> x;
    if (x < 0) { return 1; }

    int** arr = (int**)malloc(sizeof(int*) * x);
    for (int i = 0; i < x; i++) {
        arr[i] = (int*)malloc(sizeof(int) * x);
    }

    int j = 0;
    int i_temp = 1;
    for (int i = 0; i < x; i++) {
        for (int ii = i; ii >= 0; ii--) {
            arr[ii][j] = count;
            //cout << ii << " " << j << "\n";
            count++;
            j++;
            if (j > x) { break; }
            if (j == x) {
                j = ii + 1;
                ii = i + 1;
                continue;
            }
        }
        j = 0;
    }




    for (int o = 0; o < x; o++) {
        for (int p = 0; p < x; p++) {
            //cout << arr[p][o] << " ";
            cout << setw(3) << arr[p][o] << " ";
        }
        cout << "\n";
        cout << endl;
    }
    
    return 0;
}