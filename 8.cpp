#include <iostream>
#include <cmath>
using namespace std;

// Функция для нахождения среднего
double avgTemp(int t[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += t[i];
    return sum / n;
}

// Функция для нахождения дня с температурой ближе всего к средней
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
    return day + 1; // дни начинаем с 1
}

int main() {
    const int days = 31;      // март
    int temp[days];

    cout << "Введите среднесуточные температуры за март:\n";
    for (int i = 0; i < days; i++) {
        cout << "День " << i + 1 << ": ";
        cin >> temp[i];
    }

    double avg = avgTemp(temp, days);
    int day = closestDay(temp, days, avg);

    cout << "Средняя температура месяца: " << avg << "\n";
    cout << "День, ближе всего к средней: " << day << "\n";

    return 0;
}
