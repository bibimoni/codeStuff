#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<string> names(n);
    vector<int> heights(n);
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> names[i] >> heights[i];
        cnt[heights[i]]++;
    }
    int target_h = -1;
    for (auto [h, c] : cnt) {
        if (c == 7) {
            target_h = h;
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (heights[i] == target_h) {
            cout << names[i] << '\n';
        }
    }
    return 0;
}