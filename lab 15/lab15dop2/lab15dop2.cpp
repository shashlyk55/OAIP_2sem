#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// ����� ��� ������������� ���-�������
class HashTable {
private:
    vector<list<string>> table; // ������ ������� ��� �������� �������
    int size; // ����������� �������

public:
    // �����������, ���������������� ������� �������� ������������
    HashTable(int tableSize) {
        size = tableSize;
        table.resize(size);
    }

    // ������� �����������
    int hashFunction(string word) {
        int sum = 0;
        for (char c : word) {
            sum += int(c);
        }
        return sum % size;
    }

    // ������� ���������� ����� � �������
    void addWord(string word) {
        int index = hashFunction(word);
        table[index].push_back(word);
    }

    // ������� ������ ����� � �������
    bool searchWord(string word) {
        int index = hashFunction(word);
        auto& chain = table[index];
        return find(chain.begin(), chain.end(), word) != chain.end();
    }

    // ������� �������� ����, ������������ � ��������� �����
    void removeWordsStartingWith(char letter) {
        for (auto& chain : table) {
            chain.remove_if([&letter](const string& word) {
                return word[0] == letter;
                });
        }
    }
    // ������� ������ ������� �� �����
    void printTable() {
        for (int i = 0; i < size; i++) {
            cout << "��� " << i << ": ";
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
    cout << "1-����� �������\n2-������ �� �����\n3-������ �������\n4-����� �����\n5-�������� �� �����\n0-�����\n��� ������?\n";
}

int main() {
    setlocale(LC_ALL, "ru");
    string filename = "text.txt";
    int tableSize, task;
    cout << "������� ����������� ���-�������: ";
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
                cout << "������ �������� �����." << endl;
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
            cout << "������� ����� ��� ������: ";
            cin >> searchWord;
            if (hashtable.searchWord(searchWord)) {
                cout << "����� �������." << endl;
            }
            else {
                cout << "����� �� �������." << endl;
            }
        }
              break;
        case 5: {
            char removeLetter;
            cout << "������� ����� ��� �������� ����: ";
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
