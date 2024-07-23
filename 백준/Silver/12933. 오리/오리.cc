#include <bits/stdc++.h>
using namespace std;
vector<bool>vis(2500);

int main(void){
    string s;
    cin>>s;
    vis.resize(s.size());
    for(int i = 0;i<s.size();i++){
        vis[i] = false;
    }
    bool duck  = true;
    bool err = false;
    int q = 0;
    while(duck){
        duck = false;
        int cnt = 0;
        bool done = false;
        for(int i = 0;i<vis.size();i++){
            if(s[i] == 'q'&&!vis[i]&&cnt == 0){
                cnt++;
                vis[i] = true;
                duck  = true;
            }
            else if(s[i] == 'u'&&!vis[i]&&cnt ==1){
                cnt++;
                vis[i] = true;
            }
            else if(s[i] == 'a'&&!vis[i]&&cnt==2){
                vis[i] = true;
                cnt++;
            }
            else if(s[i] == 'c'&&!vis[i]&&cnt==3){
                vis[i] = true;
                cnt++;
            }
            else if(s[i] == 'k'&&!vis[i]&&cnt==4){
                cnt = 0;
                vis[i] = true;
                done = true;
                
            }
            
        }
        if(done) q++;
        if(cnt){
            err = true;
            break;
        }
    }
    for(int i = 0;i<s.size();i++){
        if(!vis[i]){
            err = true;
        }
    }
    if(err){
        cout<<"-1"<<"\n";
    }
    else{
        cout<<q<<"\n";
    }
    
    
    return 0;
}

