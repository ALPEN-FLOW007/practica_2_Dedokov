#include <iostream>
#include <cmath>
using namespace std;

//Средний
double avgTemp(int t[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += t[i];
    return sum / n;
}

int closestDay(int t[], int n, double avg) {
    int day = 0;
    double diff = fabs(t[0] - avg);
    for (int i = 1; i < n; i++) {
        double d = fabs(t[i] - avg);
        if (d < diff) {
            diff = d;
            day = i;
        }
    }
    return day + 1; 
}

int main() {
    const int days = 31;      
    int temp[days];

    cout << "Введите среднесуточные температуры за март:\n";
    for (int i = 0; i < days; i++) {
        cout << "День " << i + 1 << ": ";
        cin >> temp[i];
    }

    double avg = avgTemp(temp, days);
    int day = closestDay(temp, days, avg);

    cout << "Средняя температура за месяц : " << avg << "\n";
    cout << "День, ближе к средней температуре: " << day << "\n";

    return 0;
}
