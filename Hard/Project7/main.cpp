// Написать класс «массив». Реализовать в классе такие методы:

//  1   конструктор по умолчанию, конструктор с параметрами, конструктор копии;
//  2   деструктор;
//  3   поиск элемента в массиве по ключу;
//  4   сортировка элементов по возрастанию;
//  5   ввод с клавиатуры и вывод на экран (в виде методов класса и при помощи перегруженных операций потокового ввода и вывода);
//  6   перегрузить следующие операции:
//     +  (поэлементное сложение);
//   .  += (добавление элемента в конец массива);
//   .  –  (удаление элемента по ключу);
//     =  (присвоение);
//   .  == (сравнение по элементам);
//   .  [] (взятие элемента с заданным индексом).

#include <iostream> 
#include <iomanip>
#include <typeinfo>


using namespace std;


class MyArray {
    private:
        int *arr;
        int len_arr;

    public:
        MyArray(int len_arr_arg) {
            arr = (int*)malloc(sizeof(int) * len_arr_arg);
            len_arr = len_arr_arg;
            std::cout << "Array was been created, len = " << len_arr << std::endl;
        }

        MyArray& operator += (int num) {
            Resize(len_arr + 1);
            arr[len_arr - 1] = num;
            return *this;
        }

        MyArray& operator == (MyArray& arr2) {
            for (int i = 0; i < len_arr; i++) {
                if (arr[i] != arr2.arr[i]) {
                    std::cout << "Массивы не равны" << std::endl;
                    return *this;
                }
            }
            std::cout << "Массивы равны" << std::endl;
            return *this;
        }

        MyArray& operator - (int num) {
            int temp_len_arr = len_arr;
            int *arr_temp = (int*)malloc(sizeof(int) * len_arr);
            for (int i = 0; i < temp_len_arr; i++) {
                arr_temp[i] = arr[i];
                if (arr[i] == num) {
                    for (int j = i; j < temp_len_arr - 1; j++) {
                        arr_temp[j] = arr[j + 1];
                    }
                    len_arr--;
                    break;
                }
            }
            Resize(len_arr);
            for (int i = 0; i < len_arr; i++) {
                arr[i] = arr_temp[i];
            }
            free (arr_temp);
            return *this;
        }

        int operator[] (int index) {
            int num = arr[index];
            return num;
        }

        void Print() {
            std::cout << "\n";
            for (int i = 0; i < len_arr; i++) {
                std::cout << arr[i] << " " << std::flush;
            }
            std::cout << std::endl;
        }

        void Resize(int len_arr_arg) {
            if (arr == nullptr) {
                std::cerr << "Error: Memory allocation failed for the array." << std::endl;
                return;
            }
            if (len_arr_arg > len_arr) {
                int arr2[len_arr];
                for (int i = 0; i < len_arr; i++) {
                    arr2[i] = arr[i];
                }
                delete[] arr;
                arr = (int*)malloc(sizeof(int) * len_arr_arg);
                int i = 0;
                while (i < len_arr_arg) {
                    if (i < len_arr) {
                        arr[i] = arr2[i];
                    } else {
                        arr[i] = 0;
                    }
                    i++;
                }
                len_arr = len_arr_arg;
            } else if (len_arr_arg < len_arr) {
                int arr2[len_arr_arg];
                for (int i = 0; i < len_arr_arg; i++) {
                    arr2[i] = arr[i];
                }
                delete[] arr;
                arr = (int*)malloc(sizeof(int) * len_arr_arg);
                for (int i = 0; i < len_arr_arg; i++) {
                    arr[i] = arr2[i];
                }
                len_arr = len_arr_arg;
            }
        }

        void Fill(int num) {
            std::cout << "Array after fill: " << endl;
            // if (arr == nullptr) {
            //     std::cerr << "Error: Memory allocation failed for the array." << std::endl;
            //     return;
            // }
            for (int i = 0; i < len_arr; i++) {
                arr[i] = num;
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }

        void Find(int index) {
            while (arr == nullptr) {
                std::cout << "try find ";
            }
            if (index < len_arr | index >= 0) {
                std::cout << "Искомый элемент массива " << typeid(this).name() << ": " << arr[index] << std::flush;
            } else {
                std::cout << "Искомый элемент не найден";
            }
            std::cout << std::endl;
        }

        void Input(int len) {
            if (len > 0) {
                int input;
                std::cout << "\nВведите " << len << " чисел: ";
                int old_len = len_arr;
                Resize(len + len_arr);
                for (int i = old_len; i < len + old_len; i++) {
                    std::cin >> arr[i];
                }
                cout << "\nВведенный масив: ";
                for (int i = 0; i < len + old_len; i++) {
                    std::cout << arr[i] << " ";
                }
                std::cout << std::endl;
            }
        }

        ~MyArray() {
            delete[] arr;
            std::cout << "\nОбъект уничтожен" << std::endl;
        }
};


int main () {
    {
        MyArray myArray1(10);
        myArray1.Fill(0);
        myArray1.Find(2);
        myArray1.Input(5);
        std::cout << "arr1 += 6: ";
        myArray1 += 6;
        myArray1.Print();
        MyArray myArray2(15);
        myArray2.Fill(0);
        myArray1.Print();
        myArray2.Print();
        myArray1 == myArray2;
        int test = myArray1[2];
        std::cout << "Элемент с индексом 2: " << test << std::endl;
        std::cout << "arr1 - 5: ";
        myArray1 - 5;
        myArray1.Print();
    }
    
    //system("pause");
    return 0;
}