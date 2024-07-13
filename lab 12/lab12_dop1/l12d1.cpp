#include <iostream>
#include <iomanip>
#include <string>
#include<windows.h>
using namespace std;

struct Tree
{
    int value;
    string name;
    string rate;
    Tree* left;
    Tree* right;
};

Tree* createTree(int value, string name, string rate);
Tree* insert(Tree* root, int value, string name, string rate);
void search(Tree* root, int value);
int menu(Tree* root);
void printTree(Tree* root, int indent);

int check{}, mts = 0, a1 = 0, life = 0;
int ch;

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Tree* root = NULL;
    int value{};
    string name, rate;
    while (true)
    {
        switch (menu(root))
        {
        case 1:
            cout << "номер: ";
            cin >> value;
            cout << "имя: ";
            cin >> name;
            cout << "Тариф: \n1-MTS\n2-A1\n3-LIFE\n";
            cin >> ch;
            //cin >> rate;
            switch (ch) {
            case 1:
                rate = "MTS";
                mts++;
                break;
            case 2:
                rate = "A1";
                a1++;
                break;
            case 3:
                rate = "LIFE";
                life++;
                break;
            default: {
                cout << "ошибка\n";
                cin >> ch;
            }
            }
            root = insert(root, value, name, rate);
            break;
        case 2:
            cout << "номер для поиска: ";
            cin >> value;
            search(root, value);
            cout << endl;
            system("pause");
            break;

            break;
        case 3:
            if (mts > a1 && mts > life)
                cout << "лучший тариф МТS\n ";
            if (a1 > mts && a1 > life)
                cout << "лучший тариф А1\n ";
            if (life > mts && life > a1)
                cout << "Лучший тариф LIFE\n ";
            system("pause");
            break;
        case 0:  exit(0);
        default: exit(1);
        }
    }

    return 0;
}

int menu(Tree* root)
{
    int variant{};
    system("cls");
    cout << "Дерево:\n\n";
    printTree(root, 0);
    cout << "\n\n";
    cout << endl;
    cout << "1 - добавить элемент\n";
    cout << "2 - поиск\n";
    cout << "3 - лучший тариф\n";
    cout << "0 - выход\n";
    cout << "что делать?\n";


    while (true)
    {
        cin >> variant;
        if (!cin || variant < 0 || variant > 3)
        {
            cerr << "ошибка!\n";
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }
        break;
    }
    return variant;
}

Tree* createTree(int value, string name, string rate)
{
    Tree* node = new Tree;
    node->value = value;
    node->name = name;
    node->rate = rate;
    if (rate == "a1")
        a1++;
    if (rate == "life")
        life++;
    if (rate == "mts")
        mts++;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Tree* insert(Tree* root, int value, string name, string rate)
{
    if (root == NULL)
        return createTree(value, name, rate);

    if (value < root->value)
        root->left = insert(root->left, value, name, rate);

    else
        root->right = insert(root->right, value, name, rate);
    return root;
}

void printTree(Tree* root, int indent)
{
    if (root == NULL)
        return;
    indent += 5;
    printTree(root->right, indent);
    cout << setw(indent) << root->value << ' ' << root->name << ' ' << root->rate << endl;
    printTree(root->left, indent);
}


void search(Tree* root, int indent)
{
    if (root == NULL)
        return;
    search(root->right, indent);
    if (indent == root->value)
    {
        cout << root->value << ' ' << root->name << ' ' << root->rate << endl;
    }
    search(root->left, indent);
}
