#include <iostream>
#include <vector>
using namespace std;

void smoothRow(vector<double>& row) {
    int m = row.size();
    vector<double> old = row;

    for (int j = 0; j < m; j++) {
        if (j == 0 || j == m - 1) {
            row[j] = old[j];
        }
        else {
            row[j] = (old[j - 1] + old[j] + old[j + 1]) / 3.0;
        }
    }
}

int main() {
    int n, m;
    cout << "Введите размеры матрицы n m: ";
    cin >> n >> m;

    vector<vector<double>> a(n, vector<double>(m));
    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        smoothRow(a[i]);
    }

    cout << "Матрица после сглаживания:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}
