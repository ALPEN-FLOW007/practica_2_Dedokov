#include <iostream>
using namespace std;

int main() {
    double x1, y1, x2, y2;

    // ���� ���न��� �窨 A
    cout << "������ ���न���� �窨 A (x1 y1): ";
    cin >> x1 >> y1;

    // ���� ���न��� �窨 B
    cout << "������ ���न���� �窨 B (x2 y2): ";
    cin >> x2 >> y2;

    // ���᫥��� �����樥�⮢ k � b
    double k = (y2 - y1) * x1 * x2 / (x1 - x2);
    double b = y1 - k / x1;

    // �뢮� १����
    cout << "�������� �����樥��� �ࠢ����� y = k/x + b:" << endl;
    cout << "k = " << k << endl;
    cout << "b = " << b << endl;

    return 0;
}