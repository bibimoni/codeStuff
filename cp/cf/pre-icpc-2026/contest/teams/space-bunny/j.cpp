#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
ll modpow(ll a, ll b){ll r=1;a%=MOD;while(b){if(b&1)r=r*a%MOD;a=a*a%MOD;b>>=1;}return r;}
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        vector<ll> a(n + 1), p(n + 1, 0);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];
        ll S = p[n];
        // prefix values at valid cut positions 1..n-1
        vector<pair<ll, int>> v;
        for (int i = 1; i < n; i++) v.push_back({p[i], i});
        sort(v.begin(), v.end());
        map<ll, vector<int>> pos;
        for (auto &pr : v) pos[pr.first].push_back(pr.second);
        if (S == 0) {
            ll z = 0;
            for (int i = 1; i < n; i++) if (p[i] == 0) z++;
            printf("%lld\n", modpow(2, z));
            continue;
        }
        ll sgn = S > 0 ? 1 : -1;
        ull SS = (ull)(sgn * S);
        // rebuild prefix sums normalised to be positive total
        map<ll, vector<int>> posN;
        for (int i = 1; i < n; i++) posN[sgn * p[i]].push_back(i);
        ll ans = 1;
        // candidate strand sums: divisors of SS that appear as prefix values, <= SS/2
        for (auto &kv : posN) {
            ull v0 = (ull)kv.first;
            if (v0 == 0 || v0 > SS / 2) continue;
            if (SS % v0) continue;
            ull g = SS / v0;
            if (g < 2) continue;
            // presence check + collect layers
            bool ok = true;
            vector<const vector<int> *> layers;
            layers.reserve((size_t)g);
            for (ull j = 1; j < g; j++) {
                ull x = v0 * j;
                if (x >= SS) { ok = false; break; }
                auto it = posN.find((ll)x);
                if (it == posN.end()) { ok = false; break; }
                layers.push_back(&it->second);
            }
            if (!ok) continue;
            // chain DP
            vector<int> prevCnt;
            vector<ll> prevWays;
            prevCnt = *layers[0];
            prevWays.assign(prevCnt.size(), 1);
            for (size_t li = 1; li < layers.size(); li++) {
                const vector<int> &cur = *layers[li];
                vector<ll> curWays(cur.size());
                size_t p2 = 0; ll run = 0;
                for (size_t k = 0; k < cur.size(); k++) {
                    while (p2 < prevCnt.size() && prevCnt[p2] < cur[k]) { run += prevWays[p2]; run %= MOD; p2++; }
                    curWays[k] = run;
                }
                prevCnt = cur; prevWays.swap(curWays);
            }
            ll tot = 0;
            for (ll w : prevWays) { tot += w; tot %= MOD; }
            ans += tot; ans %= MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
