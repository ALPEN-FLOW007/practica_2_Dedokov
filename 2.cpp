#include <iostream>
using namespace std;

int main() {
    double x1, y1, x2, y2;

    cout << "������ ���न���� �窨 A (x1 y1): ";
    cin >> x1 >> y1;

    cout << "������ ���न���� �窨 B (x2 y2): ";
    cin >> x2 >> y2;

    double k = (y2 - y1) * x1 * x2 / (x1 - x2);
    double b = y1 - k / x1;

    cout << "�������� �����樥��� �ࠢ����� y = k/x + b:" << endl;
    cout << "k = " << k << endl;
    cout << "b = " << b << endl;

    return 0;
}
