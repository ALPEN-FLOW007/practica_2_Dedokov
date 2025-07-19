#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

// ===== функция загрузки цен =====
void loadPrices(map<string, int>& prices, const string& priceFile) {
    ifstream fin(priceFile);
    string veg;
    int price;
    while (fin >> veg >> price) {
        prices[veg] = price;
    }
    fin.close();
}

// ===== функция загрузки накопленного урожая =====
void loadHarvest(map<string, int>& harvest, const string& harvestFile) {
    ifstream fin(harvestFile);
    if (!fin.is_open()) return; // если файл пустой или не создан
    string veg;
    int amount;
    while (fin >> veg >> amount) {
        harvest[veg] = amount;
    }
    fin.close();
}

// ===== функция сохранения обновленного урожая =====
void saveHarvest(const map<string, int>& harvest, const string& harvestFile) {
    ofstream fout(harvestFile);
    for (auto& p : harvest) {
        fout << p.first << " " << p.second << "\n";
    }
    fout.close();
}

// ===== функция расчёта оплаты =====
void calcPayment(const map<string, int>& harvest, const map<string, int>& prices) {
    int total = 0;
    cout << "\n=== Итоги сбора и оплата ===\n";
    for (auto& p : harvest) {
        int amount = p.second;
        int cost = prices.at(p.first) * amount;
        cout << p.first << ": " << amount << " кг -> " << cost << " руб.\n";
        total += cost;
    }
    cout << "Итого к оплате: " << total << " руб.\n";
}

int main() {
    setlocale(LC_ALL, ""); // чтобы русские буквы нормально выводились

    string priceFile = "prices.txt";    // ← укажи путь к файлу с ценами
    string harvestFile = "harvest.txt"; // ← укажи путь к файлу с урожаем

    map<string, int> prices;
    map<string, int> harvest;

    // загрузить данные
    loadPrices(prices, priceFile);
    loadHarvest(harvest, harvestFile);

    cout << "Вводите данные за сегодня:\n";
    for (auto& p : prices) {
        cout << "Сколько собрали (" << p.first << "): ";
        int today;
        cin >> today;
        harvest[p.first] += today; // добавляем к общему количеству
    }

    // сохранить обновлённые данные
    saveHarvest(harvest, harvestFile);

    // показать расчёт оплаты
    calcPayment(harvest, prices);

    return 0;
}
