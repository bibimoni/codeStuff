// TL: direct simulation, vector kept LRU..MRU, O(cache size) per query.
// Correct but Theta(n * q) in the worst case.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<pair<int, long long>> c;   // (key, value), LRU front .. MRU back
        c.reserve(n);
        for (int k = 1; k <= n; k++) c.push_back({k, 0});
        while (q--) {
            int type; long long a; cin >> type >> a;
            int pos = -1;
            for (int i = 0; i < (int)c.size(); i++)
                if (c[i].first == (int)a) { pos = i; break; }
            if (type == 1) {
                long long b; cin >> b;
                if (pos != -1) c.erase(c.begin() + pos);
                else c.erase(c.begin());            // evict LRU
                c.push_back({(int)a, b});
            } else {
                if (pos == -1) { cout << -1 << '\n'; continue; }
                long long val = c[pos].second;
                cout << val << ' ' << (int)c.size() - pos << '\n';  // back = order 1
                c.erase(c.begin() + pos);
                c.push_back({(int)a, val});
            }
        }
    }
    return 0;
}
