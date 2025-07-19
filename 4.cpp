#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x) {
    // �ਢ������ x � [0, 2) �� ����� 2
    double mod_x = fmod(x, 2);
    if (mod_x < 0) mod_x += 2;

    if (mod_x <= 1.0)
        return mod_x * mod_x - 2.25 * mod_x;
    else
        return mod_x - 1.25;
}

int main() {
    int n;
    cout << "������ ��⭮� �᫮ �祪: ";
    cin >> n;

    if (n <= 0 || n % 2 != 0) {
        cout << "�訡��: �᫮ �祪 ������ ���� ������⥫�� � ����.\n";
        return 1;
    }

    double a = -4.0, b = 4.0;
    double h = (b - a) / (n - 1);

    cout << fixed << setprecision(4);
    for (int i = 0; i < n; ++i) {
        double x = a + i * h;
        cout << "x = " << setw(6) << x << " | f(x) = " << setw(8) << f(x) << '\n';
    }

    return 0;
}