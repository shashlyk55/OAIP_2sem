#include<iostream>
#include <algorithm>
using namespace std;

void permute(int* arr, int n, int k = 0) {
	if (k == n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = k; i < n; i++) {
		swap(arr[k], arr[i]); 
		permute(arr, n, k + 1);     
		swap(arr[k], arr[i]);  
	}
}

void main() {
	srand(time(NULL));
	int n;
	cout << "n = ";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		//arr[i] = rand() % 10;
		arr[i] = i + 1;
	}
	cout << endl;
	permute(arr, n);
	system("pause");
}