#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

// ����������� �������
double function(double x) 
{
    return x - 1.0 / (3 + sin(3.6 * x));
}

// ������������ ������� ��� ������ ��������
double g(double x) 
{
    return 1.0 / (3 + sin(3.6 * x));
}

int main() 
{
    setlocale(LC_ALL, "Rus");
    double x0 = 0.1; // ��������� ��������
    double epsilon = 0.00001; // ��������
    double x = x0;
    double x_new = g(x);
    int iteration = 0;

    auto start = chrono::high_resolution_clock::now();

    while (fabs(x_new - x) >= epsilon) 
    {
        x = x_new;
        x_new = g(x);
        iteration++;
        cout << "�������� " << iteration << ": x = " << x_new << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "��������� �������� x0: " << x0 << endl;
    cout << "���������� ��������: " << iteration << endl;
    cout << "������: " << x_new << endl;
    cout << "����������� �����: " << duration << " �����������" << endl;

    return 0;
}
