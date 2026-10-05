#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        // Step 1: Find the depth by going both left and right
        int d_left = 0, d_right = 0;
        
        // Go left
        while (true) {
            cout << "? L" << endl;
            int ret;
            cin >> ret;
            if (ret == 0) break;
            d_left++;
        }
        
        // Go right
        while (true) {
            cout << "? R" << endl;
            int ret;
            cin >> ret;
            if (ret == 0) break;
            d_right++;
        }
        
        // Navigate back to root using d_left ? B queries
        for (int i = 0; i < d_left; i++) {
            cout << "? B" << endl;
            int ret;
            cin >> ret;
        }
        
        if (d_left == 0) {
            cout << "! 1" << endl;
            continue;
        }
        
        // If left and right depths are equal, it's a perfect tree
        if (d_left == d_right) {
            long long N = (1LL << (d_left + 1)) - 1;
            cout << "! " << N << endl;
            continue;
        }
        
        // Otherwise, use binary search (simplified)
        // For now, just output based on left depth
        long long filled = (1LL << d_left) - 1;
        cout << "! " << filled + 1 << endl;  // just last level = 1
    }
    
    return 0;
}