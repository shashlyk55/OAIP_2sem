#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string a;
    stack<char> st;
    getline(cin, a);

    for (int i = 0; i < a.length() / 2; i++) {
        st.push(a[i]);
    }
    while (!st.empty()) {
            cout << st.top();
            st.pop();
        }
    for (int i = a.length(); i >= a.length() / 2; i--) {
        cout << a[i];
    }

    
    cout << endl;

    return 0;
}