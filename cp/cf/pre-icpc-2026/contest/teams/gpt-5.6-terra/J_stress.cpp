#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long fast(vector<int> a) {
    int n = a.size(); vector<long long> p(n + 1); map<long long, vector<int>> w; w[0] = {0};
    for (int i = 1; i <= n; ++i) w[p[i] = p[i - 1] + a[i - 1]].push_back(i);
    if (!p[n]) { long long z = 1; for (int i = 1; i < n; ++i) if (!p[i]) z *= 2; return z; }
    long long ans = 0;
    for (int d = 1; d <= n; ++d) if (p[n] % d == 0) {
        if (d == 1) { ++ans; continue; }
        vector<int> old; vector<long long> ways;
        for (int j = 1; j < d; ++j) {
            auto it = w.find(p[n] / d * j); if (it == w.end()) break;
            vector<long long> now(it->second.size()); int q = 0; long long s = 0;
            for (int i = 0; i < (int)now.size(); ++i) { if (j == 1) now[i] = 1; else { while (q < (int)old.size() && old[q] < it->second[i]) s += ways[q++]; now[i] = s; } }
            old = it->second; ways = now;
            if (j == d - 1) for (auto x : ways) ans += x;
        }
    }
    return ans;
}
int main() {
    mt19937 rng(1);
    for (int z = 0; z < 10000; ++z) {
        int n = rng() % 9 + 1; vector<int> a(n); for (int &x : a) x = int(rng() % 5) - 2;
        long long brute = 0;
        for (int mask = 0; mask < (1 << (n - 1)); ++mask) { long long s = 0, want = LLONG_MIN; bool ok = 1; for (int i = 0; i < n; ++i) { s += a[i]; if (i == n - 1 || (mask >> i & 1)) { if (want == LLONG_MIN) want = s; else ok &= want == s; s = 0; } } brute += ok; }
        assert(fast(a) == brute);
    }
}
