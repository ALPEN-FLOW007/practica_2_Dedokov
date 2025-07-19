#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int totalPay;

    cout << "Часы\tОплата (руб)\n";
    for (int hours = 1; hours <= 24; ++hours) {
        totalPay = 0;
        int rate = 25;

        for (int h = 1; h <= hours; ++h) {
            if (h <= 6)
                totalPay += 25;
            else {
                rate *= 2;
                totalPay += rate;
            }
        }

        cout << setw(2) << hours << "\t" << setw(5) << totalPay << "\n";
    }

    return 0;
}
