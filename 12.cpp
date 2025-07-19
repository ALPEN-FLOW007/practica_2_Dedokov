#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Student {
    string name;
    string surname;
    int year;     // ��� ���祭��, ���ਬ�� 5
    char letter;  // �㪢� �����, ���ਬ�� 'A'
};

// �㭪�� ���������� ������ �祭���
void addStudent(vector<Student>& students) {
    Student s;
    cout << "������ ���: ";
    cin >> s.name;
    cout << "������ 䠬����: ";
    cin >> s.surname;
    cout << "������ ��� ���祭�� (���ਬ�� 5): ";
    cin >> s.year;
    cout << "������ �㪢� �����: ";
    cin >> s.letter;
    students.push_back(s);
}

// �㭪�� �뢮�� ���ଠ樨 �� ����� �祭���
void printStudent(const Student& s) {
    cout << s.name << " " << s.surname << " ? "
        << s.year << s.letter << " �����" << endl;
}

// �㭪�� �뢮�� �ᥩ ���ଠ樨
void printAll(const vector<Student>& students) {
    cout << "\n=== ���᮪ �祭���� ===\n";
    for (auto& s : students) {
        printStudent(s);
    }
}

void classesMoreThanN(const vector<Student>& students, int n) {
    map<pair<int, char>, int> counts;
    for (auto& s : students) {
        counts[{s.year, s.letter}]++;
    }
    cout << "\n=== ������, ��� ����� 祬 " << n << " �祭���� ===\n";
    for (auto& kv : counts) {
        if (kv.second > n) {
            cout << kv.first.first << kv.first.second
                << " �����: " << kv.second << " �祭����\n";
        }
    }
}

// �㭪��: ᪮�쪮 祫���� ����� � ������ ��ࠫ����
void countParallels(const vector<Student>& students) {
    map<int, int> counts;
    for (auto& s : students) {
        counts[s.year]++;
    }
    cout << "\n=== ������⢮ �祭���� �� ��ࠫ���� ===\n";
    for (auto& kv : counts) {
        cout << kv.first << " �����: " << kv.second << " �祭����\n";
    }
}

int main() {
    vector<Student> students;

    int choice;
    do {
        cout << "\n����:\n";
        cout << "1 - �������� �祭���\n";
        cout << "2 - �뢥�� ��� �祭����\n";
        cout << "3 - �஢���� ������ � �᫮� �祭���� ����� N\n";
        cout << "4 - ������� ������⢮ �祭���� �� ��ࠫ����\n";
        cout << "0 - ��室\n";
        cout << "��� �롮�: ";
        cin >> choice;

        if (choice == 1) {
            addStudent(students);
        }
        else if (choice == 2) {
            printAll(students);
        }
        else if (choice == 3) {
            int n;
            cout << "������ N: ";
            cin >> n;
            classesMoreThanN(students, n);
        }
        else if (choice == 4) {
            countParallels(students);
        }

    } while (choice != 0);

    return 0;
}
