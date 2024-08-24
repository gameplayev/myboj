#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

struct cmp {
    bool operator()(pii&a, pii&b){
        if(a.second != b.second){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int dia, bac;
    cin >> dia >> bac;
    
    priority_queue<pii, vector<pii>, cmp> pq;
    
    for(int i = 0; i < dia; i++){
        int a, b;
        cin >> a >> b;
        pq.emplace(a, b);
    }
    
    multiset<int> bags;
    for(int i = 0; i < bac; i++){
        int bag;
        cin >> bag;
        bags.insert(bag);
    }

    long long res = 0;

    while (!pq.empty()) {
        auto [weight, value] = pq.top();
        pq.pop();
        
        auto it = bags.lower_bound(weight);
        
        if (it != bags.end()) {
            res += value;
            bags.erase(it);
        }
    }

    cout << res << "\n";
    
    return 0;
}
