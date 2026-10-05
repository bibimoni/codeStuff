#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

int main() {
    int t; scanf("%d", &t);
    string out;
    out.reserve(1 << 20);
    while (t--) {
        int n; scanf("%d", &n);
        vector<long long> a(n);
        for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];
        long long S = pref[n];
        if (S == 0) {
            long long z = 0;
            for (int i = 1; i < n; i++) if (pref[i] == 0) z++;
            long long ans = 1, base = 2, e = z;
            while (e) {
                if (e & 1) ans = ans * base % MOD;
                base = base * base % MOD;
                e >>= 1;
            }
            out += to_string(ans);
            out += '\n';
            continue;
        }
        unordered_map<long long, vector<int>> pos;
        pos.reserve(n * 2 + 8);
        for (int i = 1; i < n; i++) pos[pref[i]].push_back(i);
        unordered_set<long long> cand;
        cand.reserve(n * 2 + 8);
        for (int i = 1; i < n; i++) {
            long long v = pref[i];
            if (v == 0) continue;
            if (S % v != 0) continue;
            long long k = S / v;
            if (k >= 2 && k <= n) cand.insert(v);
        }
        long long ans = 1; // whole necklace (k = 1)
        vector<long long> pcum;
        vector<int> ppos;
        for (long long tt : cand) {
            long long k = S / tt;
            ppos.clear(); pcum.clear();
            // process levels 1..k-1 with two-pointer merge over sorted position lists
            bool ok = true;
            for (long long j = 1; j < k; j++) {
                auto it = pos.find(j * tt);
                if (it == pos.end() || it->second.empty()) { ok = false; break; }
                const vector<int>& P = it->second;
                // build prev cumulative from (ppos, pcum); for level 1 prev = single virtual position -inf with cum 1
                vector<long long> newcum(P.size());
                long long run = 0;
                size_t idx = 0;
                if (j == 1) {
                    run = 1; // virtual cut before everything
                    for (size_t m = 0; m < P.size(); m++) newcum[m] = 1 % MOD;
                    // ways to cut level1 at any position = 1 each
                } else {
                    size_t psz = ppos.size();
                    for (size_t m = 0; m < P.size(); m++) {
                        int p = P[m];
                        while (idx < psz && ppos[idx] < p) { run += pcum[idx]; if (run >= MOD) run -= MOD; idx++; }
                        newcum[m] = run;
                    }
                }
                ppos = P;
                pcum = std::move(newcum);
                if (j == k - 1) {
                    long long tot = 0;
                    for (long long v : pcum) { tot += v; if (tot >= MOD) tot -= MOD; }
                    ans += tot;
                    if (ans >= MOD) ans -= MOD;
                }
            }
            (void)ok;
        }
        out += to_string(ans);
        out += '\n';
    }
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
