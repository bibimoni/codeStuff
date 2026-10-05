#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n, m, k;
        scanf("%lld %lld %lld", &n, &m, &k);
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        ll cnt = 0;
        bool done = false;
        do {
            ll inv = 0;
            for (int i = 0; i < n && !done; i++)
                for (int j = i + 1; j < n; j++)
                    inv += p[i] > p[j];
            if (inv == m && ++cnt == k) {
                for (int i = 0; i < n; i++)
                    printf("%d%c", p[i], " \n"[i + 1 == n]);
                done = true;
            }
        } while (!done && next_permutation(p.begin(), p.end()));
        if (!done) printf("-1\n");
    }
    return 0;
}
