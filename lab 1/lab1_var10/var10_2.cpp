#include<iostream>
#include<cstring>
using namespace std;

void sort(char* s) {
	int i;
	for (int c = 'a'; c <= 'z'; c++) {
		for (i = 0; s[i] != '\0'; i++) {
			if ((s[i] == (char)c && s[i - 1] == ' ') || (i == 0 && s[i] == (char)c)) {
				for (int j = i; s[j] != ' '; j++) {
					cout << s[j];
				}
				cout << " ";
			}
		}
	}
}
 
void main() {
	char s[200];
	gets_s(s);
	sort(s);
}
