#include <bits/stdc++.h>
using namespace std;

static const unsigned long long INF = (unsigned long long)4e18;

int main() {
    int t; scanf("%d", &t);
    // c[i][j] = # perms of length i with exactly j inversions, capped at INF
    static vector<vector<unsigned long long>> c;
    static int maxi = 0;
    auto ensure = [&](int n) {
        if (maxi >= n) return;
        int old = maxi;
        c.resize(n + 1);
        c[0] = {1};
        for (int i = old + 1; i <= n; i++) {
            int maxinv = i * (i - 1) / 2;
            c[i].assign(maxinv + 1, 0);
            const auto& prev = c[i - 1];
            __int128 run = 0;
            int pmax = (int)prev.size() - 1;
            for (int j = 0; j <= maxinv; j++) {
                if (j <= pmax) run += prev[j];
                if (j - i >= 0 && j - i <= pmax) run -= prev[j - i];
                c[i][j] = run >= (__int128)INF ? INF : (unsigned long long)run;
            }
        }
        maxi = n;
    };
    string out;
    out.reserve(1 << 20);
    while (t--) {
        int n, m; long long k;
        scanf("%d %d %lld", &n, &m, &k);
        ensure(n);
        if (m > n * (n - 1) / 2 || k > c[n][m]) { out += "-1\n"; continue; }
        vector<char> used(n + 1, 0);
        int rem = n;
        long long mm = m;
        long long kk = k;
        string line;
        bool fail = false;
        for (int pos = 0; pos < n; pos++) {
            int chosen = -1;
            int maxrem = (rem - 1) * (rem - 2) / 2;
            for (int v = 1; v <= n; v++) {
                if (used[v]) continue;
                int smaller = 0;
                for (int u = 1; u < v; u++) if (!used[u]) smaller++;
                if (mm < smaller) continue;
                long long need = mm - smaller;
                long long ways = (need > maxrem) ? 0 : c[rem - 1][need];
                if (kk > ways) { kk -= ways; continue; }
                chosen = v;
                mm = need;
                break;
            }
            if (chosen == -1) { fail = true; break; }
            used[chosen] = 1;
            rem--;
            if (pos) line += ' ';
            line += to_string(chosen);
        }
        if (fail) out += "-1\n";
        else { out += line; out += '\n'; }
    }
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
