#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countAdjacentDuplicates(const string& s) {
    int count = 0;
    for (size_t i = 0; i + 1 < s.size(); i++) {
        if (s[i] == s[i + 1]) count++;
    }
    return count;
}

string compressString(const string& s) {
    if (s.empty()) return "";
    string res;
    res.push_back(s[0]);
    for (size_t i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            res.push_back(s[i]);
        }
    }
    return res;
}

int main() {

    string test;
    cout << "Введите строку для проверки: ";
    getline(cin, test);
    int duplicates = countAdjacentDuplicates(test);
    cout << "Число подряд идущих одинаковых символов: " << duplicates << "\n";

    string pathIn  = "F1.txt";
    string pathOut = "F2.txt";

    ifstream fin(pathIn);
    ofstream fout(pathOut);

    if (!fin.is_open()) {
        cout << "Не удалось открыть файл F1!\n";
        return 1;
    }
    if (!fout.is_open()) {
        cout << "Не удалось создать файл F2!\n";
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        string processed = compressString(line);
        fout << processed << "\n";
    }

    fin.close();
    fout.close();

    cout << "Обработка файла завершена. Результат записан в F2.\n";
    return 0;
}
