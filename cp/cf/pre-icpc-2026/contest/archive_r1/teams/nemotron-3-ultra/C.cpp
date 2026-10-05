#include <bits/stdc++.h>
using namespace std;

bool check_node(long long x) {
    // assumes we are at root (1)
    vector<int> path;
    long long tmp = x;
    while (tmp > 1) {
        path.push_back(tmp & 1);
        tmp >>= 1;
    }
    reverse(path.begin(), path.end());
    
    for (int dir : path) {
        cout << "? " << (dir == 0 ? 'L' : 'R') << '\n';
        cout.flush();
        int res;
        cin >> res;
        if (res == 0) {
            // failed, return to root
            while (true) {
                cout << "? B\n";
                cout.flush();
                cin >> res;
                if (res == 0) break;
            }
            return false;
        }
    }
    // reached x, return to root
    for (size_t i = 0; i < path.size(); ++i) {
        cout << "? B\n";
        cout.flush();
        int res;
        cin >> res;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        // find depth by going left
        int d = 0;
        while (true) {
            cout << "? L\n";
            cout.flush();
            int res;
            cin >> res;
            if (res == 0) break;
            d++;
        }
        // return to root
        while (true) {
            cout << "? B\n";
            cout.flush();
            int res;
            cin >> res;
            if (res == 0) break;
        }
        
        long long lo = 1LL << d;
        long long hi = (1LL << (d + 1)) - 1;
        if (hi > 1000000000000000000LL) hi = 1000000000000000000LL;
        
        while (lo < hi) {
            long long mid = (lo + hi + 1) >> 1;
            if (check_node(mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        
        cout << "! " << lo << '\n';
        cout.flush();
    }
    return 0;
}