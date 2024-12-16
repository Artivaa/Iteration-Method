#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

// Определение функции
double function(double x) 
{
    return x - 1.0 / (3 + sin(3.6 * x));
}

// Переписываем функцию для метода итераций
double g(double x) 
{
    return 1.0 / (3 + sin(3.6 * x));
}

int main() 
{
    setlocale(LC_ALL, "Rus");
    double x0 = 0.1; // Начальное значение
    double epsilon = 0.00001; // Точность
    double x = x0;
    double x_new = g(x);
    int iteration = 0;

    auto start = chrono::high_resolution_clock::now();

    while (fabs(x_new - x) >= epsilon) 
    {
        x = x_new;
        x_new = g(x);
        iteration++;
        cout << "Итерация " << iteration << ": x = " << x_new << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "Начальное значение x0: " << x0 << endl;
    cout << "Количество итераций: " << iteration << endl;
    cout << "Корень: " << x_new << endl;
    cout << "Затраченное время: " << duration << " микросекунд" << endl;

    return 0;
}
