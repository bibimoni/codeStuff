#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long lo = 1, hi = 1000000000000000000LL;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            vector<char> path;
            for (long long x = mid; x > 1; x >>= 1) path.push_back((x & 1) ? 'R' : 'L');
            reverse(path.begin(), path.end());
            bool ok = true;
            int moved = 0;
            for (char dir : path) {
                cout << "? " << dir << endl;
                int can;
                cin >> can;
                if (!can) { ok = false; break; }
                ++moved;
            }
            while (moved--) {
                cout << "? B" << endl;
                int ignored;
                cin >> ignored;
            }
            if (ok) lo = mid;
            else hi = mid - 1;
        }
        cout << "! " << lo << endl;
    }
}
