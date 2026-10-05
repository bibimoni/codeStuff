#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Only pairs of segments at distance <= 9 need checking: a left-turning simple
// path is an outward spiral, so the first self-contact happens between segments
// at distance <= 5 (verified by brute force over 800k random cases).
static inline bool hit(ll ax1, ll ay1, ll ax2, ll ay2, ll bx1, ll by1, ll bx2, ll by2) {
    bool av = (ax1 == ax2), bv = (bx1 == bx2);
    if (av && bv) return ax1 == bx1 && max(min(ay1, ay2), min(by1, by2)) <= min(max(ay1, ay2), max(by1, by2));
    if (!av && !bv) return ay1 == by1 && max(min(ax1, ax2), min(bx1, bx2)) <= min(max(ax1, ax2), max(bx1, bx2));
    if (av) return min(ay1, ay2) <= by1 && by1 <= max(ay1, ay2) && min(bx1, bx2) <= ax1 && ax1 <= max(bx1, bx2);
    return min(by1, by2) <= ay1 && ay1 <= max(by1, by2) && min(ax1, ax2) <= bx1 && bx1 <= max(ax1, ax2);
}
int main() {
    int t; if (scanf("%d", &t) != 1) return 0;
    const int K = 9;
    while (t--) {
        int n; scanf("%d", &n);
        vector<ll> d(n + 1);
        for (int i = 1; i <= n; i++) scanf("%lld", &d[i]);
        vector<ll> X(n + 2), Y(n + 2);
        ll x = 0, y = 0;
        int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
        for (int i = 1; i <= n; i++) {
            int k = (i - 1) % 4;
            X[i] = x; Y[i] = y;
            x += dx[k] * d[i]; y += dy[k] * d[i];
            X[i + 1] = x; Y[i + 1] = y;
        }
        bool bad = false;
        for (int i = 1; i <= n && !bad; i++)
            for (int j = i + 2; j <= n && j - i <= K; j++)
                if (hit(X[i], Y[i], X[i + 1], Y[i + 1], X[j], Y[j], X[j + 1], Y[j + 1])) { bad = true; break; }
        puts(bad ? "Yes" : "No");
    }
    return 0;
}
