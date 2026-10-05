#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 0; tc < T; tc++) {
        // Step 1: walk left to find height h
        long long h = 0;
        while (true) {
            cout << "? L" << endl;
            int r; cin >> r;
            if (r == 0) break;
            h++;
        }
        if (h == 0) {
            cout << "! 1" << endl;
            continue;
        }
        // return to root
        for (long long i = 0; i < h; i++) {
            cout << "? B" << endl;
            int r; cin >> r;
        }
        // binary search last-level index: exists(0)=true known
        unsigned long long lo = 0, hi = (h == 64 ? ~0ULL : ((1ULL << h) - 1ULL));
        // h <= 59 since N <= 1e18 < 2^60
        auto exists = [&](unsigned long long m) -> bool {
            long long depth = 0;
            bool ok = true;
            for (long long b = h - 1; b >= 0; b--) {
                if ((m >> b) & 1ULL) cout << "? R" << endl;
                else cout << "? L" << endl;
                int r; cin >> r;
                if (r == 0) { ok = false; break; }
                depth++;
            }
            for (long long i = 0; i < depth; i++) {
                cout << "? B" << endl;
                int r; cin >> r;
            }
            return ok;
        };
        while (lo < hi) {
            unsigned long long mid = lo + (hi - lo + 1) / 2;
            if (exists(mid)) lo = mid;
            else hi = mid - 1;
        }
        unsigned long long N = (1ULL << h) + lo;
        cout << "! " << N << endl;
    }
    return 0;
}
