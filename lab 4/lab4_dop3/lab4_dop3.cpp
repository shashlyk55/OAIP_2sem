#include <iostream>
#include <string>
#include<windows.h>

#define SIZE 10
#define pSize 3
using namespace std;

struct sanatorium {
	string name;
	string loc;
	string prof;
	string tickets;
};

struct profiles {

};

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	sanatorium sanator[SIZE];
	string profile[3] = {
		"������� ������",
		"����������� �����������",
		"�������������� �����������"
	};
	int size;
	char p;
	bool flag = false;
	cout << "������� ���������� ����������: ";
	cin >> size;
	for (int i = 0; i < size; i++) {
		do {
			cout << "��������: ";
			getchar();
			getline(cin, sanator[i].name);
			flag = false;
			for (int j = 0; sanator[i].name[j] != '\0';j++) {
				if ((sanator[i].name[j] < '�' || sanator[i].name[j]>'�') && (sanator[i].name[j] < '�' || sanator[i].name[j] > '�')) {
					cout << "������\n";
					flag = true;
					break;
				}
			}
		} while (flag);
		flag = false;
		do {
			cout << "������������: ";
			getchar();
			getline(cin, sanator[i].loc);
			flag = false;
			for (int j = 0; sanator[i].loc[j] != '\0'; j++) {
				if ((sanator[i].loc[j] < '�' || sanator[i].loc[j]>'�') && (sanator[i].loc[j] < '�' || sanator[i].loc[j]>'�')&& sanator[i].loc[j]!=' ') {
					cout << "������\n";
					flag = true;
					break;
				}
			}
		} while (flag);
		flag = false;
		do {
			cout << "������� �������:\n1-������� ������\n2-����������� �����������\n3-�������������� �����������\n";
			cout << "������� ����� ������� �������: ";
			cin >> p;
			flag = false;
			if (p < '0' || p>'3') {
				cout << "������\n";
				flag = true;
				break;
			}
		} while (flag);
		sanator[i].prof = profile[p - '0' - 1];
		flag = false;
		do {
			cout << "���������� �������: ";
			getchar();
			getline(cin, sanator[i].tickets);
			flag = false;
			for (int j = 0; sanator[i].tickets[j] != '\0'; j++) {
				if (sanator[i].tickets[j] < '0' || sanator[i].tickets[j]>'9') {
					cout << "������\n";
					flag = true;
					break;
				}
			}
		} while (flag);
		cout << endl;
	}

	for (int i = 0; i < pSize;i++) {
		for (char c = '�'; c <= '�'; c++) {
			for (int j = 0; j < size; j++) {
				if (profile[i] == sanator[j].prof && sanator[j].name[0] == c) {
					cout << sanator[j].name << '\t' << sanator[j].loc << '\t' << sanator[j].prof << '\t' << sanator[j].tickets << '\n';
				}
			}
		}
	}
                                                                       
	string search_name, search_location, search_profile,search_ticket;
	bool found = false; 
	char sw;
	
	
	while (true) {
		cout << "1 - ����� ���������\n2 - �����";
		cin >> sw;
		while (sw < '1' || sw>'2') {
			cout << "������\n1 - ����� ���������\n2 - �����";
			cin >> sw;
		}
		switch (sw) {
		case '1': {
			do {
				cout << "��������: ";
				getchar();
				getline(cin, search_name);
				flag = false;
				for (int j = 0; search_name[j] != '\0'; j++) {
					if ((search_name[j] < '�' || search_name[j]>'�') && (search_name[j] < '�' || search_name[j] > '�')) {
						cout << "������\n";
						flag = true;
						break;
					}
				}
			} while (flag);
			for (int i = 0; i < SIZE && !found; i++) {
				if (sanator[i].name == search_name) {
					found = true;
					search_location = sanator[i].loc;
					search_profile = sanator[i].prof;
					search_ticket = sanator[i].tickets;
				}
			}
			if (found) {
				cout << "\n��������: " << search_name << endl;
				cout << "������������: " << search_location << endl;
				cout << "�������: " << search_profile << endl;
				cout << "�������: " << search_ticket << endl;
			}
			else {
				cout << "\n��������� �� ������";
			}
		}break;
		case '2': {
			exit(1);
		}
		}
	}
}