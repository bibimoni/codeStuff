// G - Gardener's Turtle
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P { ll x, y; };
// do two axis-parallel segments share at least one point? (touching counts)
static bool hit(P a1, P a2, P b1, P b2) {
    bool av = (a1.x == a2.x), bv = (b1.x == b2.x);
    if (av && bv) {
        if (a1.x != b1.x) return false;
        ll l1 = min(a1.y, a2.y), r1 = max(a1.y, a2.y);
        ll l2 = min(b1.y, b2.y), r2 = max(b1.y, b2.y);
        return max(l1, l2) <= min(r1, r2);
    }
    if (!av && !bv) {
        if (a1.y != b1.y) return false;
        ll l1 = min(a1.x, a2.x), r1 = max(a1.x, a2.x);
        ll l2 = min(b1.x, b2.x), r2 = max(b1.x, b2.x);
        return max(l1, l2) <= min(r1, r2);
    }
    if (av) {  // a vertical, b horizontal
        ll y = b1.y, x = a1.x;
        return min(a1.y, a2.y) <= y && y <= max(a1.y, a2.y) &&
               min(b1.x, b2.x) <= x && x <= max(b1.x, b2.x);
    }
    ll y = a1.y, x = b1.x;
    return min(b1.y, b2.y) <= y && y <= max(b1.y, b2.y) &&
           min(a1.x, a2.x) <= x && x <= max(a1.x, a2.x);
}
int main() {
    int t;
    cin >> t;
    const int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
    while (t--) {
        int n;
        cin >> n;
        vector<P> p(n + 1);
        p[0] = {0, 0};
        for (int i = 0; i < n; i++) {
            ll d;
            cin >> d;
            p[i + 1] = {p[i].x + dx[i % 4] * d, p[i].y + dy[i % 4] * d};
        }
        bool found = false;
        for (int i = 0; i < n && !found; i++)
            for (int j = i + 3; j < n && j <= i + 5; j++)
                if (hit(p[i], p[i + 1], p[j], p[j + 1])) { found = true; break; }
        cout << (found ? "Yes" : "No") << "\n";
    }
}
