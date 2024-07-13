#include <iostream>
#include <string>
#include <algorithm>
#include<windows.h>
using namespace std;

struct TRAIN {
	string destination;
	string number;
	char time[5];
};

bool comp(TRAIN a, TRAIN b) {
	return (a.destination < b.destination);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int N = 2; 

	TRAIN trains[N]; 
	bool flag = false;
	cout << "Введите данные о поездах: \n";

	for (int i = 0; i < N; i++) { 
		do {
			cout << "Пункт назначения: ";
			getline(cin, trains[i].destination);
			flag = false;
			for (int j = 0; trains[i].destination[j] != '\0'; j++) {
				if ((trains[i].destination[j] < 'а' || trains[i].destination[j] > 'я') && (trains[i].destination[j] > 'Я' || trains[i].destination[j] < 'А')&& trains[i].destination[j]!=' ') {
					flag = true;
					cout << "Ошибка\n";
					break;
				}
			}
		} while (flag);
		
		do{
			cout << "Номер: "; 
			getline(cin, trains[i].number);
			flag = false;
			for (int j = 0; trains[i].number[j] != '\0'; j++) {
				if (trains[i].number[j] < '0' || trains[i].number[j] > '9') {
					flag = true;
					cout << "Ошибка\n";
					break;
				}
			}
		}while (flag);

		do {
			cout << "Время: ";
			cin >> trains[i].time;
			flag = false;
			for (int j = 0; j < 5; j++) {
				if ((trains[i].time[2] != '.' || ((trains[i].time[0] < '0' || trains[i].time[0]>'2') || (trains[i].time[3] < '0' || trains[i].time[3]>'5')) || (trains[i].time[0] == '2' && trains[i].time[1] > '4') || (trains[i].time[0] != '2' && (trains[i].time[1] < '0' || trains[i].time[1]>'9')))) {
					cout << "Ошибка\n";
					flag = true;
					break;
				}
			}
		} while (flag);
		flag = false;
		cout << endl;
		getchar();
	}
	sort(trains, trains + N, comp); 
	char inputTime[5];
	do {
		cout << "\n\nВведите время: ";
		cin >> inputTime;
		for (int j = 0; j < 5; j++) {
			if ((inputTime[2] != '.' || ((inputTime[0] < '0' || inputTime[0]>'2') || (inputTime[3] < '0' || inputTime[3]>'5')) || (inputTime[0] == '2' && inputTime[1] > '4') || (inputTime[0] != '2' && (inputTime[1] < '0' || inputTime[1]>'9')))) {
				cout << "Ошибка\n";
				flag = true;
				break;
			}
		}
	} while (flag);
	flag = false;
	bool check = false;

	for (int i = 0; i < N; i++) {
		if ((((int)inputTime[0] - '0') * 10 + ((int)inputTime[1] - '0') <= ((int)trains[i].time[0] - '0') * 10 + ((int)trains[i].time[1] - '0'))&& (((int)inputTime[3] - '0') * 10 + ((int)inputTime[4] - '0') < ((int)trains[i].time[3] - '0') * 10 + ((int)trains[i].time[4] - '0'))) {
			cout << "\n\n" << "Пункт назначения :" << trains[i].destination << "\nНомер: " << trains[i].number << "\nВремя: " << trains[i].time << endl;
			check = true;
		}
	}
	if (!check) {
		cout << "\n\nНету поездов после этого времени";
	}
	return 0;
}