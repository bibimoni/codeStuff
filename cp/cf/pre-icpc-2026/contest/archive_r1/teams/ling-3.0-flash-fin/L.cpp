#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[300005], b[300005];
ll prefix[300005];
ll total_val;

ll getQ(int i) { return i <= 0 ? 0 : prefix[i]; }

ll costCW(int s, int t) {
    if (s == t) return 0;
    if (t > s) return getQ(t-1) - getQ(s-1);
    return total_val - getQ(s-1) + getQ(t-1);
}

bool passesThrough(int from, int to, int x) {
    if (x < 1 || x > n) return false;
    if (from == to || from == x || to == x) return false;
    if (from < to) return (from < x && x < to);
    return !(to < x && x < from);
}

int main(){
    int t; scanf("%d", &t);
    while (t--) {
        int q;
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
        
        prefix[0] = 0;
        for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + a[i];
        total_val = prefix[n];
        
        while (q--) {
            int type; scanf("%d", &type);
            if (type == 1) {
                int s, tt; scanf("%d%d", &s, &tt);
                if (tt == n+1) {
                    ll ans = b[s];
                    for (int i = 1; i <= n; i++) if (i != s) {
                        ans = min(ans, costCW(s, i) + b[i]);
                        ans = min(ans, costCW(i, s) + b[i]);
                    }
                    printf("%lld\n", ans);
                } else {
                    int t = tt;
                    ll ans = min(costCW(s, t), total_val - costCW(s, t));
                    ans = min(ans, b[s] + b[t]);
                    
                    for (int i = 1; i <= n; i++) if (i != s && i != t) {
                        if (!passesThrough(s, i, t))
                            ans = min(ans, costCW(s, i) + b[i] + b[t]);
                        if (!passesThrough(i, s, t))
                            ans = min(ans, costCW(i, s) + b[i] + b[t]);
                        if (!passesThrough(i, t, s))
                            ans = min(ans, b[s] + b[i] + costCW(i, t));
                        if (!passesThrough(t, i, s))
                            ans = min(ans, b[s] + b[i] + costCW(t, i));
                    }
                    
                    printf("%lld\n", ans);
                }
            } else if (type == 2) {
                int x; ll w; scanf("%d%lld", &x, &w);
                a[x] = w;
                for (int i = x; i <= n; i++) prefix[i] = prefix[i-1] + a[i];
                total_val = prefix[n];
            } else {
                int x; ll w; scanf("%d%lld", &x, &w);
                b[x] = w;
            }
        }
    }
}
