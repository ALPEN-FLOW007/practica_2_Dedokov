#include <iostream>
#include <cmath>
using namespace std;

int main() {
    char again;
    do {
        double a, b, c;
        cout << "Введите стороны треугольника : ";
        cin >> a >> b >> c;

        if (a + b > c && a + c > b && b + c > a) {
            if (a > b) swap(a, b);
            if (b > c) swap(b, c);
            if (a > b) swap(a, b);

            double a2 = a * a, b2 = b * b, c2 = c * c;

            if (fabs(c2 - (a2 + b2)) < 1e-6)
                cout << "Прямоугольный\n";
            else if (c2 < a2 + b2)
                cout << "Остроугольный\n";
            else
                cout << "Тупоугольный\n";
        } else {
            cout << "Треугольник не существует\n";
        }

        cout << "Повторить? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');
    
    return 0;
}
