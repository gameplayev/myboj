#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> 
#include <limits.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    vector<int> solutions(N);
    for (int i = 0; i < N; i++) {
        cin >> solutions[i];
    }

    sort(solutions.begin(), solutions.end());

    int left = 0;
    int right = N - 1;
    int bestSum = INT_MAX; 
    pair<int, int> bestPair; 

    while (left < right) {
        int currentSum = solutions[left] + solutions[right];


        if (abs(currentSum) < abs(bestSum)) {
            bestSum = currentSum;
            bestPair = {solutions[left], solutions[right]};
        }

       
        if (currentSum > 0) {
            right--;
        } else {
            
            left++;
        }
    }

    
    cout << bestPair.first << " " << bestPair.second << endl;

    return 0;
}