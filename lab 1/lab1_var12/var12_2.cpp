#include<iostream>
using namespace std;//x1=1.56836	x2=-0.352844
float func1(float q) {
	float f;
	f = pow(q, 3) + 2 * q - 7;
	return f;
}

float func2(float q) {
	float f;
	f = exp(q) + 2 * q;
	return f;
}

float dihotom(float &a, float &b, float (* function)(float), float e = 0.001) {
	float x;
	do {
		x = (a + b) / 2;
		if ((function(a)) * (function(x)) <= 0) {
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
	cout << "x1 = " << dihotom(y1, z1, func1) << endl;
	cin >> y2 >> z2;
	cout << "x2 = " << dihotom(y2, z2, func2);
}
