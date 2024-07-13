#include <iostream>
#include <string>
#include <algorithm>
#include<windows.h>
using namespace std;

const int countOfStudents = 100;

struct FIO {
	string fam;
	string name;
	string otch;
}fio;

struct students {
	FIO fio;
	char number;
	char marks[10];
};

int character(struct students* arr, int numStudents);
void checkingExams(struct students* arr, int iteration);

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int numSt;
	char num;
	bool flag = false;
	cout << "������� ���������� ���������: ";
	cin >> num;
	while (num < '0' || num > '9') {
		cout << "������\n������� ���������� ���������: ";
		cin >> num;
		continue;

	}
	numSt = num - '0';
	getchar();
	students* exams = new students[numSt];
	cout << "������� ���������� � ���������: \n��� ��������: \n";
	for (int i = 0; i < numSt; i++) {
		do {
			cout << "�������: ";
			getline(cin, exams[i].fio.fam);
			flag = false;
			for (int j = 0; exams[i].fio.fam[j] != '\0'; j++) {
				if ((exams[i].fio.fam[j] < '�' || exams[i].fio.fam[j] > '�') && (exams[i].fio.fam[j] > '�' || exams[i].fio.fam[j] < '�')) {
					flag = true;
					cout << "������\n";
					break;
				}
			}
		} while (flag);
		flag = false;
		do {
			cout << "���: ";
			getline(cin, exams[i].fio.name);
			flag = false;
			for (int j = 0; exams[i].fio.name[j] != '\0'; j++) {
				if ((exams[i].fio.name[j] < '�' || exams[i].fio.name[j] > '�') && (exams[i].fio.name[j] > '�' || exams[i].fio.name[j] < '�')) {
					flag = true;
					cout << "������\n";
					break;
				}
			}
		} while (flag);
		flag = false;
		do {
			cout << "��������: ";
			getline(cin, exams[i].fio.otch);
			flag = false;
			for (int j = 0; exams[i].fio.otch[j] != '\0'; j++) {
				if ((exams[i].fio.otch[j] < '�' || exams[i].fio.otch[j] > '�') && (exams[i].fio.otch[j] > '�' || exams[i].fio.otch[j] < '�')) {
					flag = true;
					cout << "������\n";
					break;
				}
			}
		} while (flag);
		flag = false;
		cout << "���������� ���������: ";
		cin >> exams[i].number;
		while (exams[i].number < '0' || exams[i].number > '9') {
			cout << "������\n���������� ���������: ";
			cin >> exams[i].number;
		}
		cout << "������ �� ��������: ";
		for (int j = 0; j < exams[i].number - '0'; j++) {
			cin >> exams[i].marks[j];
			while (exams[i].marks[j] < '0' || exams[i].marks[j] > '9') {
				cout << "������\n������ �� �������: ";
				cin >> exams[i].marks[j];
			}
		}
		cout << endl;
		checkingExams(exams, i);
		getchar();
	}
	printf("\n����������: %d ��������� ��������� ����� �������� �������!", character(exams, numSt));
	delete[] exams;
	
}

int character(struct students* arr,int numStudents) {
	float res;
	int count = 0, sum = 0;
	for (int i = 0; i < numStudents; i++) {
		for (int j = 0; j < arr[i].number - '0'; j++) {
			if (arr[i].marks[j] - '0' >= 4) {
				count++;
			}
		}
		if (count == arr[i].number - '0') {
			sum++;
		}
		count = 0;
	}
	res = ((float)sum / numStudents) * 100;
	return (int)res;
}

void checkingExams(struct students* arr, int i) {
	int count = 0, j;
	
	for (j = 0; j < arr[i].number - '0'; j++) {
		if (arr[i].marks[j] - '0' >= 4) {
			count++;
		}
	}
	if (count == arr[i].number - '0') {
		cout << "������� " << arr[i].fio.fam << " ���� �������� �������." << endl;
	}
	else
		cout << "������� " << arr[i].fio.fam << " - �������." << endl;
}