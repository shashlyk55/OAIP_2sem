#include<iostream>
using namespace std;//x1=-0.00195312	x2=-0.736328
float foo1(float q) {
	float f;
	f = sin(q) + pow(q, 3);
	return f;
}

float foo2(float q) {
	float f;
	f = 0.4 + pow(q, 3);
	return f;
}

float dihotom(float& a, float& b, float (*func)(float), float e = 0.001) {
	float x;
	do {
		x = (a + b) / 2;
		if ((func(a)) * (func(x)) <= 0) {
			b = x;
		}
		else
		{
			a = x;
		}
	} while (abs(a - b) > 2 * e);
	return x;
}

void main()
{
	float y1, z1, y2, z2;
	cin >> y1 >> z1;
	cout << "x = " << dihotom(y1, z1, foo1) << endl;
	cin >> y2 >> z2;
	cout << "x = " << dihotom(y2, z2, foo2);
}