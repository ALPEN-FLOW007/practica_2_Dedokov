#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

// 1. Расстояние между двумя точками
double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

// Вывод таблицы расстояний
void showDistances(double X[], double Y[], int n) {
    cout << "Таблица расстояний:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist(X[i], Y[i], X[j], Y[j]) << "\t";
        }
        cout << "\n";
    }
}

// Наибольшее расстояние
double maxDistance(double X[], double Y[], int n) {
    double maxd = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double d = dist(X[i], Y[i], X[j], Y[j]);
            if (d > maxd) maxd = d;
        }
    }
    return maxd;
}

// 2. Ввод массива
void inputArr(int a[], int &n) {
    cout << "Введите размер: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "]=";
        cin >> a[i];
    }
}

// Вывод массива
void printArr(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
}

// Сжатие (убрать <0)
int compress(int a[], int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) a[k++] = a[i];
    }
    return k;
}

// 3. Генерация массива
void genArr(int *a, int n) {
    for (int i = 0; i < n; i++) a[i] = rand()%21 - 10; // [-10..10]
}

// Копия положительных
int positiveOnly(int *src, int n, int *dst) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (src[i] > 0) dst[k++] = src[i];
    }
    return k;
}

int main() {
    srand(time(0));
    // -------- Задание 1 --------
    const int n = 4;
    double X[n] = {0, 1, 2, 3};
    double Y[n] = {0, 1, 4, 9};
    showDistances(X,Y,n);
    cout << "Наибольшее расстояние: " << maxDistance(X,Y,n) << "\n\n";

    // -------- Задание 2 --------
    int a[100], m;
    inputArr(a,m);
    cout << "Исходный массив: ";
    printArr(a,m);
    m = compress(a,m);
    cout << "После сжатия: ";
    printArr(a,m);
    cout << "\n";

    // -------- Задание 3 --------
    int b[10];
    genArr(b,10);
    cout << "Сгенерировано: ";
    printArr(b,10);
    int c[10];
    int k = positiveOnly(b,10,c);
    cout << "Только >0: ";
    printArr(c,k);

    return 0;
}
