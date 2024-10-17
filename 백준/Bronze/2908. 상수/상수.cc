#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string a,b;
    int n;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(a[0]>b[0])
        cout << a;
    else if(a[0]<b[0])
        cout << b;
    else
    {
        if(a[1]>b[1])
            cout << a;
        else if(a[1]<b[1])
            cout << b;
        else
            if(a[2]>b[2])
                cout << a;
            else if(a[2]<b[2])
                cout << b;
    } 
    
    return 0;
}