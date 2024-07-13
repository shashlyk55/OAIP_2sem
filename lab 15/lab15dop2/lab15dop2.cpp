#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// Класс для представления хеш-таблицы
class HashTable {
private:
    vector<list<string>> table; // Вектор списков для хранения цепочек
    int size; // Размерность таблицы

public:
    // Конструктор, инициализирующий таблицу заданной размерностью
    HashTable(int tableSize) {
        size = tableSize;
        table.resize(size);
    }

    // Функция хеширования
    int hashFunction(string word) {
        int sum = 0;
        for (char c : word) {
            sum += int(c);
        }
        return sum % size;
    }

    // Функция добавления слова в таблицу
    void addWord(string word) {
        int index = hashFunction(word);
        table[index].push_back(word);
    }

    // Функция поиска слова в таблице
    bool searchWord(string word) {
        int index = hashFunction(word);
        auto& chain = table[index];
        return find(chain.begin(), chain.end(), word) != chain.end();
    }

    // Функция удаления слов, начинающихся с указанной буквы
    void removeWordsStartingWith(char letter) {
        for (auto& chain : table) {
            chain.remove_if([&letter](const string& word) {
                return word[0] == letter;
                });
        }
    }
    // Функция вывода таблицы на экран
    void printTable() {
        for (int i = 0; i < size; i++) {
            cout << "Хеш " << i << ": ";
            for (const string& word : table[i]) {
                cout << word << " ";
            }
            cout << endl;
        }
    }
    void clearHashTable() {
        for (int i = 0; i < size; ++i) {
            table[i].clear();
        }
    }
};


void menu() {
    cout << "1-вывод таблицы\n2-чтение из файла\n3-чистка таблицы\n4-поиск слова\n5-удаление по букве\n0-выход\nчто делать?\n";
}

int main() {
    setlocale(LC_ALL, "ru");
    string filename = "text.txt";
    int tableSize, task;
    cout << "Введите размерность хеш-таблицы: ";
    cin >> tableSize;
    HashTable hashtable(tableSize);
    while (true) {
        menu();
        cin >> task;
        switch (task) {
        case 1: {
            hashtable.printTable();
        }
              break;
        case 2: {
            ifstream file(filename);
            if (file.is_open()) {
                string word;
                while (file >> word) {
                    hashtable.addWord(word);
                }
                file.close();
            }
            else {
                cout << "Ошибка открытия файла." << endl;
                return 0;
            }
        }
              break;
        case 3: {
            hashtable.clearHashTable();
        }
              break;
        case 4: {
            string searchWord;
            cout << "Введите слово для поиска: ";
            cin >> searchWord;
            if (hashtable.searchWord(searchWord)) {
                cout << "Слово найдено." << endl;
            }
            else {
                cout << "Слово не найдено." << endl;
            }
        }
              break;
        case 5: {
            char removeLetter;
            cout << "Введите букву для удаления слов: ";
            cin >> removeLetter;
            hashtable.removeWordsStartingWith(removeLetter);
        }
              break;
        case 0: {
            exit(1);
        }
        }
    }

    return 0;
}
