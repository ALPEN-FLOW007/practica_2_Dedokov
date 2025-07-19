#include <iostream>
#include <cmath>
using namespace std;

int main() {
    char again;
    do {
        double a, b, c;
        cout << "������ ��஭� ��㣮�쭨��: ";
        cin >> a >> b >> c;

        if (a + b > c && a + c > b && b + c > a) {
            if (a > b) swap(a, b);
            if (b > c) swap(b, c);
            if (a > b) swap(a, b);

            double a2 = a * a, b2 = b * b, c2 = c * c;

            if (fabs(c2 - (a2 + b2)) < 1e-6)
                cout << "��אַ㣮���\n";
            else if (c2 < a2 + b2)
                cout << "����㣮���\n";
            else
                cout << "�㯮㣮���\n";
        } else {
            cout << "��㣮�쭨� �� �������\n";
        }

        cout << "�������? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');
    
    return 0;
}
