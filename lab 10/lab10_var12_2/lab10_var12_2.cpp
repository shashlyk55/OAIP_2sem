#include<iostream>
using namespace std;


float task(int n, float x) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return x;
	}
	return (x / n) * task(n - 2, x);
}



void main() {
	float res, x;
	int n;
	cout << "n = ";
	cin >> n;
	cout << "x = ";
	cin >> x;
	//res = pow(x, n) / fact(n);
	cout << "res = " << task(n, x) << endl;
}