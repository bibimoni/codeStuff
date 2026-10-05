#include <bits/stdc++.h>
using namespace std;

const unsigned long long CAP = 1000000000000000000ULL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, target;
        unsigned long long kth;
        cin >> n >> target >> kth;
        vector<vector<unsigned long long>> ways(n + 1);
        ways[0].push_back(1);
        for (int sz = 1; sz <= n; ++sz) {
            int hi = sz * (sz - 1) / 2;
            ways[sz].resize(hi + 1);
            vector<int> prefWhole(ways[sz - 1].size() + 1);
            vector<unsigned long long> prefRem(ways[sz - 1].size() + 1);
            for (int x = 0; x < (int)ways[sz - 1].size(); ++x) {
                prefWhole[x + 1] = prefWhole[x];
                prefRem[x + 1] = prefRem[x] + ways[sz - 1][x];
                if (prefRem[x + 1] >= CAP) {
                    prefRem[x + 1] -= CAP;
                    ++prefWhole[x + 1];
                }
            }
            for (int inv = 0; inv <= hi; ++inv) {
                int left = max(0, inv - sz + 1);
                int right = min(inv, (int)ways[sz - 1].size() - 1);
                int whole = prefWhole[right + 1] - prefWhole[left];
                long long rem = (long long)prefRem[right + 1] - (long long)prefRem[left];
                if (rem < 0) rem += CAP, --whole;
                ways[sz][inv] = whole > 0 ? CAP : (unsigned long long)rem;
            }
        }
        if (ways[n][target] < kth) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> values(n);
        iota(values.begin(), values.end(), 1);
        for (int sz = n; sz; --sz) {
            for (int r = 0; r < sz; ++r) {
                int need = target - r;
                unsigned long long block = need >= 0 && need < (int)ways[sz - 1].size()
                    ? ways[sz - 1][need] : 0;
                if (kth > block) kth -= block;
                else {
                    cout << values[r] << (sz == 1 ? '\n' : ' ');
                    values.erase(values.begin() + r);
                    target = need;
                    break;
                }
            }
        }
    }
}
