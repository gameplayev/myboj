#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> x;
vector<int> lis, lisIndices;

void calculateLIS() {
    lis.push_back(x.front().second);
    lisIndices.push_back(0);

    for (int i = 1; i < x.size(); i++) {
        int currentValue = x[i].second;

        if (lis.back() < currentValue) {
            lis.push_back(currentValue);
            lisIndices.push_back(lis.size() - 1);
        } else {
            int left = 0;
            int right = lis.size() - 1;

            while (left < right) {
                int mid = (left + right) / 2;
                if (lis[mid] < currentValue) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            lis[left] = currentValue;
            lisIndices.push_back(left);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        x.push_back(make_pair(a, b));
    }

    sort(x.begin(), x.end());

    calculateLIS();

    cout << n - lis.size() << "\n";

    int targetIndex = lis.size() - 1;
    vector<int> elementsToRemove;

    for (int i = lisIndices.size() - 1; i >= 0; i--) {
        if (targetIndex == lisIndices[i]) {
            targetIndex--;
        } else {
            elementsToRemove.push_back(x[i].first);
        }
    }

    sort(elementsToRemove.begin(), elementsToRemove.end());
    for (int elem : elementsToRemove) {
        cout << elem << "\n";
    }

    return 0;
}
