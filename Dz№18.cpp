// Dz№18.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Задача 1
//Создайте функцию, которая принимает от 1 - го до
//5 - ти(включительно) разных чисел, после чего
//возвращает их сумму.Для решения необходимо
//использовать параметры по умолчанию.Учтите, что в
//функции должен быть один обязательный параметр.

//Задача 2
//Создайте встраиваемую функцию, которая
//принимает три числа и возвращает их среднее
//арифметическое.

//Задача 3
//Создайте перегруженную функцию для нахождения
//максимального из трёх переданных в неё значений.
//Функция должна поддерживать типы int, short и double.
//Также функция должна выводить тип переданных в неё
//значений.

//Задача 4
//Напишите шаблонную функцию, которая принимает
//массив любого типа и его длину типа int.Функция должна найти первое отрицательное число в массиве и
//обнулить все элементы массива, которые находятся
//справа от него.


#include <iostream>

//1
int sumOfNumbers(int num1, int num2 = 0, int num3 = 0, int num4 = 0, int num5 = 0) {
    return num1 + num2 + num3 + num4 + num5;
}


//2
inline double average(int a, int b, int c) {
    return static_cast<double>(a + b + c) / 3;
}


//3
template <typename T>
T max(T a, T b, T c) {
    std::cout << "Тип переданных значений: " << typeid(T).name() << std::endl;
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}
//4
template <typename T>
void processArray(T arr[], int length) {
    bool foundNegative = false;
    for (int i = 0; i < length; ++i) {
        if (foundNegative) {
            arr[i] = 0;
        }
        else if (arr[i] < 0) {
            foundNegative = true;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    //1
    int result1 = sumOfNumbers(5);
    int result2 = sumOfNumbers(2, 4);
    int result3 = sumOfNumbers(1, 3, 5);
    int result4 = sumOfNumbers(1, 2, 3, 4);
    int result5 = sumOfNumbers(1, 2, 3, 4, 5);

    std::cout << "Result 1: " << result1 << std::endl;
    std::cout << "Result 2: " << result2 << std::endl;
    std::cout << "Result 3: " << result3 << std::endl;
    std::cout << "Result 4: " << result4 << std::endl;
    std::cout << "Result 5: " << result5 << std::endl;



    //2

    int num1, num2, num3;

    std::cout << "Введите три числа: ";
    std::cin >> num1 >> num2 >> num3;

    double avg = average(num1, num2, num3);

    std::cout << "Среднее арифметическое: " << avg << std::endl;
    //3

    int intVal1 = 10, intVal2 = 20, intVal3 = 15;
    short shortVal1 = 5, shortVal2 = 8, shortVal3 = 3;
    double doubleVal1 = 12.5, doubleVal2 = 9.8, doubleVal3 = 15.3;

    std::cout << "Максимальное из трех целых чисел: " << max(intVal1, intVal2, intVal3) << std::endl;
    std::cout << "Максимальное из трех short чисел: " << max(shortVal1, shortVal2, shortVal3) << std::endl;
    std::cout << "Максимальное из трех double чисел: " << max(doubleVal1, doubleVal2, doubleVal3) << std::endl;

    //4
    int intArray[] = { 1, 2, -3, 4, 5, -6, 7 };
    int length = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < length; ++i) {
        std::cout << intArray[i] << " ";
    }

    processArray(intArray, length);

    std::cout << "\nProcessed array: ";
    for (int i = 0; i < length; ++i) {
        std::cout << intArray[i] << " ";
    }


    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
