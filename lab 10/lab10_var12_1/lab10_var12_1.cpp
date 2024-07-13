#include<iostream>
using namespace std;

//Вычислить выражение в правой части, используя рекурсию.y=cosx+cos2x+cos3x+...cos nx

int n;
float x;
//int q = 1;
float y = 0, a;

float task(int q, float x) {
	
	a = cos(q * x);
	y += a;
	if (1 == q) {
		return y;
	}
	else
		return task(q - 1, x);
}

void main() {
	cout << "n = ";
	cin >> n;
	cout << "x = ";
	cin >> x;
	while (cos(x) > 1 || cos(x) < -1) {
		cout << "Error\n";
		cout << "x = ";
		cin >> x;
	}	
	cout << endl << task(n, x);
}