#include <bits/stdc++.h>
using namespace std;

int n;
string a[100010];

bool com(const string &s, const string &s1) {
    return s + s1 > s1 + s;
}

int main(void) {
    cin >> n;
    bool flag = false;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] != "0") flag = true;
    }

    if (!flag) {
        cout << "0";
        return 0;
    }

    sort(a, a + n, com);

    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    
    return 0;
}
