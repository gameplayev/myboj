#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int time=0;
    for(int i=1;i<=str.length();i++)
    {
        for(int j=1;j<=6;j++)
        {
            if(str[i-1]-64<=(j-1)*3 && str[i-1]-64>=(j-2)*3+1)
            {
                time += 1+j;
                break;
            }
                
        }
        if(str[i-1]-64>=16&&str[i-1]-64<=19)
            time += 8;
        if(str[i-1]-64>=20&&str[i-1]-64<=22)
            time += 9;
        if(str[i-1]-64>=23)
            time += 10;
    }
    cout << time;
    return 0;
}