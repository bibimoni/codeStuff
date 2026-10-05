#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        if (k == 1) {
            long long m = a[1];
            for (int i = 2; i <= n; i++) m = min(m, a[i]);
            printf("%lld\n", m);
            continue;
        }
        vector<long long> pref(n + 1);
        pref[1] = a[1];
        for (int i = 2; i <= n; i++) pref[i] = min(pref[i - 1], a[i]);
        long long ans = LLONG_MAX;
        for (int j = k; j <= n; j++) ans = min(ans, a[j] + pref[j - k + 1]);
        printf("%lld\n", ans);
    }
    return 0;
}
