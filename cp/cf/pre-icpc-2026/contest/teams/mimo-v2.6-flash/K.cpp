#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    string out;
    out.reserve(1 << 20);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        long long ans;
        if (k == 1) {
            ans = *min_element(a.begin(), a.end());
        } else {
            vector<int> suff(n);
            suff[n - 1] = a[n - 1];
            for (int i = n - 2; i >= 0; i--) suff[i] = min(a[i], suff[i + 1]);
            ans = LLONG_MAX;
            for (int L = 0; L + k - 1 < n; L++)
                ans = min(ans, (long long)a[L] + suff[L + k - 1]);
        }
        out += to_string(ans);
        out += '\n';
    }
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
