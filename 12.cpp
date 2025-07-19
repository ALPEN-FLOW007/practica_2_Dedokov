#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Student {
    string name;
    string surname;
    int year;     // год обучения, например 5
    char letter;  // буква класса, например 'A'
};

// функция добавления нового ученика
void addStudent(vector<Student>& students) {
    Student s;
    cout << "Введите имя: ";
    cin >> s.name;
    cout << "Введите фамилию: ";
    cin >> s.surname;
    cout << "Введите год обучения (например 5): ";
    cin >> s.year;
    cout << "Введите букву класса: ";
    cin >> s.letter;
    students.push_back(s);
}

// функция вывода информации об одном ученике
void printStudent(const Student& s) {
    cout << s.name << " " << s.surname << " ? "
        << s.year << s.letter << " класс" << endl;
}

// функция вывода всей информации
void printAll(const vector<Student>& students) {
    cout << "\n=== Список учеников ===\n";
    for (auto& s : students) {
        printStudent(s);
    }
}

void classesMoreThanN(const vector<Student>& students, int n) {
    map<pair<int, char>, int> counts;
    for (auto& s : students) {
        counts[{s.year, s.letter}]++;
    }
    cout << "\n=== Классы, где больше чем " << n << " учеников ===\n";
    for (auto& kv : counts) {
        if (kv.second > n) {
            cout << kv.first.first << kv.first.second
                << " класс: " << kv.second << " учеников\n";
        }
    }
}

// функция: сколько человек учится в каждой параллели
void countParallels(const vector<Student>& students) {
    map<int, int> counts;
    for (auto& s : students) {
        counts[s.year]++;
    }
    cout << "\n=== Количество учеников по параллелям ===\n";
    for (auto& kv : counts) {
        cout << kv.first << " класс: " << kv.second << " учеников\n";
    }
}

int main() {
    vector<Student> students;

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1 - Добавить ученика\n";
        cout << "2 - Вывести всех учеников\n";
        cout << "3 - Проверить классы с числом учеников больше N\n";
        cout << "4 - Посчитать количество учеников по параллелям\n";
        cout << "0 - Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 1) {
            addStudent(students);
        }
        else if (choice == 2) {
            printAll(students);
        }
        else if (choice == 3) {
            int n;
            cout << "Введите N: ";
            cin >> n;
            classesMoreThanN(students, n);
        }
        else if (choice == 4) {
            countParallels(students);
        }

    } while (choice != 0);

    return 0;
}
