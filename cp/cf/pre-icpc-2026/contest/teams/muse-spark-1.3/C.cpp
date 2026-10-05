#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 0; tc < T; tc++) {
        // find height: go left until fail
        long long H = 0;
        while (true) {
            cout << "? L" << endl;
            int r;
            cin >> r;
            if (r == 1) H++;
            else break;
        }
        long long ans;
        if (H == 0) {
            ans = 1;
        } else {
            // go back to root
            for (long long i = 0; i < H; i++) {
                cout << "? B" << endl;
                int r; cin >> r;
            }
            unsigned long long B = 1ULL << H;
            auto exists = [&](unsigned long long v) -> bool {
                int down = 0;
                for (long long d = H - 1; d >= 0; d--) {
                    int bit = (v >> d) & 1ULL;
                    cout << (bit ? "? R" : "? L") << endl;
                    int r; cin >> r;
                    if (r == 0) {
                        for (int i = 0; i < down; i++) { cout << "? B" << endl; int rr; cin >> rr; }
                        return false;
                    }
                    down++;
                }
                for (long long i = 0; i < H; i++) { cout << "? B" << endl; int rr; cin >> rr; }
                return true;
            };
            unsigned long long lo = 1, hi = B;
            while (lo < hi) {
                unsigned long long mid = (lo + hi + 1) / 2;
                if (exists(B + mid - 1)) lo = mid;
                else hi = mid - 1;
            }
            ans = (long long)(B + lo - 1);
        }
        cout << "! " << ans << endl;
    }
    return 0;
}
