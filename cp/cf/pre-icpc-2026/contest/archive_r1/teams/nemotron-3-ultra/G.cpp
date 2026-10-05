#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> d(n);
        for (int i = 0; i < n; ++i) cin >> d[i];
        
        bool cross = false;
        for (int i = 3; i < n; ++i) {
            // Case 1: cross with i-3
            if (d[i] >= d[i-2] && d[i-1] <= d[i-3]) {
                cross = true;
                break;
            }
            // Case 2: cross with i-4
            if (i >= 4) {
                if (d[i-1] == d[i-3] && d[i] + d[i-4] >= d[i-2]) {
                    cross = true;
                    break;
                }
            }
            // Case 3: cross with i-5
            if (i >= 5) {
                if (d[i-2] >= d[i-4] && d[i-3] >= d[i-1] &&
                    d[i-1] + d[i-5] >= d[i-3] && d[i] + d[i-4] >= d[i-2]) {
                    cross = true;
                    break;
                }
            }
        }
        cout << (cross ? "Yes" : "No") << '\n';
    }
    return 0;
}