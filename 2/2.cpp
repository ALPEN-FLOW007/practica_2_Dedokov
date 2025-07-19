#include <iostream>
using namespace std;

int main() {
    double x1, y1, x2, y2;

    // Ввод координат точки A
    cout << "Введите координаты точки A (x1 y1): ";
    cin >> x1 >> y1;

    // Ввод координат точки B
    cout << "Введите координаты точки B (x2 y2): ";
    cin >> x2 >> y2;

    // Вычисление коэффициентов k и b
    double k = (y2 - y1) * x1 * x2 / (x1 - x2);
    double b = y1 - k / x1;

    // Вывод результата
    cout << "Найденные коэффициенты уравнения y = k/x + b:" << endl;
    cout << "k = " << k << endl;
    cout << "b = " << b << endl;

    return 0;
}
