// brute force for D: p reachable are 7-smooth
#include <bits/stdc++.h>
using namespace std;
int main() {
    // enumerate all 7-smooth numbers up to 1e9 * 9
    vector<long long> v;
    long long lim = 1000000000LL;
    for (long long a = 1; a <= lim; a *= 2)
      for (long long b = a; b <= lim; b *= 3)
        for (long long c = b; c <= lim; c *= 5)
          for (long long d = c; d <= lim; d *= 7) v.push_back(d);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    fprintf(stderr, "smooth count %zu\n", v.size());
    // h interval helper
    auto hwin = [&](long long r) -> int {
        if (r <= 9) return 1;
        long long hi = 9;
        while (true) {
            if (r <= 2 * hi) return 0;
            long long nhi = 18 * hi;
            if (r <= nhi) return 1;
            hi = nhi;
        }
    };
    for (long long n = 2; n <= 3000; n++) {
        // dp over v ascending: win(p) for p < n
        map<long long, int> win;
        for (int ix = (int)v.size()-1; ix >= 0; ix--) { long long p = v[ix];
            if (p >= n) continue;
            int w = 0;
            for (int k = 2; k <= 9; k++) {
                long long q = p * k;
                if (q >= n) { w = 1; break; }
                if (!win[q]) { w = 1; break; }
            }
            win[p] = w;
        }
        int bf = win[1];
        int got = hwin(n);
        if (bf != got) { printf("MISMATCH n=%lld bf=%d got=%d\n", n, bf, got); return 1; }
    }
    // random large checks
    mt19937 rng(12345);
    for (int it = 0; it < 300; it++) {
        long long n = 1 + rng() % 1000000000LL;
        map<long long, int> win;
        for (int ix = (int)v.size()-1; ix >= 0; ix--) { long long p = v[ix];
            if (p >= n) continue;
            int w = 0;
            for (int k = 2; k <= 9; k++) {
                long long q = p * k;
                if (q >= n) { w = 1; break; }
                if (!win[q]) { w = 1; break; }
            }
            win[p] = w;
        }
        if (win[1] != hwin(n)) { printf("RMISMATCH n=%lld\n", n); return 1; }
    }
    printf("D OK\n");
}
