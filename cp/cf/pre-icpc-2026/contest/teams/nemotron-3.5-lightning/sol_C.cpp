#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        // Step 1: Go left from root as far as possible
        int d = 0;
        while (true) {
            cout << "? L" << endl;
            int ret;
            cin >> ret;
            if (ret == 0) break;
            d++;
        }
        
        // Now we're at the leftmost node at depth d
        // Navigate back to root using ? B queries
        for (int i = 0; i < d; i++) {
            cout << "? B" << endl;
            int bret;
            cin >> bret;
            if (bret == 0) break;  // at root
        }
        
        if (d == 0) {
            // Single node tree
            cout << "! 1" << endl;
            continue;
        }
        
        // Step 2: Go right from root as far as possible
        int d_right = 0;
        while (true) {
            cout << "? R" << endl;
            int ret;
            cin >> ret;
            if (ret == 0) break;
            d_right++;
        }
        
        // Navigate back to root
        for (int i = 0; i < d; i++) {
            cout << "? B" << endl;
            int bret;
            cin >> bret;
            if (bret == 0) break;
        }
        
        // If d == d_right, it's a perfect full binary tree
        if (d == d_right) {
            long long N = (1LL << (d + 1)) - 1;
            cout << "! " << N << endl;
            continue;
        }
        
        // Otherwise, last level is partially filled
        // Last level can have up to 2^d nodes, filled from left to right
        // Binary search for the rightmost existing position (0-indexed)
        long long low = 0, high = (1LL << d) - 1;
        
        auto check_position = [&](long long pos) -> bool {
            // pos is 0-indexed position on last level (d-bit binary)
            // 0 = go left, 1 = go right at each level, starting from root
            for (int bit = d - 1; bit >= 0; bit--) {
                if ((pos >> bit) & 1) {
                    cout << "? R" << endl;
                } else {
                    cout << "? L" << endl;
                }
                int ret;
                cin >> ret;
                if (ret == 0) {
                    // Navigate back to root
                    for (int k = 0; k < d; k++) {
                        cout << "? B" << endl;
                        int bret;
                        cin >> bret;
                        if (bret == 0) break;
                    }
                    return false;
                }
            }
            // Successfully reached the node; navigate back to root
            for (int k = 0; k < d; k++) {
                cout << "? B" << endl;
                int bret;
                cin >> bret;
                if (bret == 0) break;
            }
            return true;
        };
        
        while (low < high) {
            long long mid = (low + high + 1) / 2;
            if (check_position(mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        
        // Total = perfect top part (2^d - 1) + (low + 1) nodes on last level
        long long ans = (1LL << d) - 1 + (low + 1);
        cout << "! " << ans << endl;
    }
    
    return 0;
}