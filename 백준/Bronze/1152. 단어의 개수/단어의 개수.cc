#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    int c = 0;
    getline(cin,str);
    for(int i=1;i<=str.size();i++)
    {
        if(str[i-1]==' '){
            c++;
        }
            
    }
    if(str[0]==' ')
        c--;
    if(str[str.size()-1]==' ')
        c--;
    cout << c+1;

    return 0;
}