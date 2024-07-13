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
	cout << "Введите количество студентов: ";
	cin >> num;
	while (num < '0' || num > '9') {
		cout << "Ошибка\nВведите количество студентов: ";
		cin >> num;
		continue;

	}
	numSt = num - '0';
	getchar();
	students* exams = new students[numSt];
	cout << "Введите информацию о студентах: \nФИО студента: \n";
	for (int i = 0; i < numSt; i++) {
		do {
			cout << "Фамилия: ";
			getline(cin, exams[i].fio.fam);
			flag = false;
			for (int j = 0; exams[i].fio.fam[j] != '\0'; j++) {
				if ((exams[i].fio.fam[j] < 'а' || exams[i].fio.fam[j] > 'я') && (exams[i].fio.fam[j] > 'Я' || exams[i].fio.fam[j] < 'А')) {
					flag = true;
					cout << "Ошибка\n";
					break;
				}
			}
		} while (flag);
		flag = false;
		do {
			cout << "Имя: ";
			getline(cin, exams[i].fio.name);
			flag = false;
			for (int j = 0; exams[i].fio.name[j] != '\0'; j++) {
				if ((exams[i].fio.name[j] < 'а' || exams[i].fio.name[j] > 'я') && (exams[i].fio.name[j] > 'Я' || exams[i].fio.name[j] < 'А')) {
					flag = true;
					cout << "Ошибка\n";
					break;
				}
			}
		} while (flag);
		flag = false;
		do {
			cout << "Отчество: ";
			getline(cin, exams[i].fio.otch);
			flag = false;
			for (int j = 0; exams[i].fio.otch[j] != '\0'; j++) {
				if ((exams[i].fio.otch[j] < 'а' || exams[i].fio.otch[j] > 'я') && (exams[i].fio.otch[j] > 'Я' || exams[i].fio.otch[j] < 'А')) {
					flag = true;
					cout << "Ошибка\n";
					break;
				}
			}
		} while (flag);
		flag = false;
		cout << "Количество экзаменов: ";
		cin >> exams[i].number;
		while (exams[i].number < '0' || exams[i].number > '9') {
			cout << "Ошибка\nКоличество экзаменов: ";
			cin >> exams[i].number;
		}
		cout << "Оценки за экзамены: ";
		for (int j = 0; j < exams[i].number - '0'; j++) {
			cin >> exams[i].marks[j];
			while (exams[i].marks[j] < '0' || exams[i].marks[j] > '9') {
				cout << "Ошибка\nОценка за экзамен: ";
				cin >> exams[i].marks[j];
			}
		}
		cout << endl;
		checkingExams(exams, i);
		getchar();
	}
	printf("\nСтатистика: %d процентов студентов сдали экзамены успешно!", character(exams, numSt));
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
		cout << "Студент " << arr[i].fio.fam << " сдал экзамены успешно." << endl;
	}
	else
		cout << "Студент " << arr[i].fio.fam << " - бездарь." << endl;
}