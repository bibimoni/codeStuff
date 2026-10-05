#include <bits/stdc++.h>
using namespace std;

struct Segment {
    long long x1, y1, x2, y2;
};

bool intersects(const Segment& a, const Segment& b) {
    bool aVertical = (a.x1 == a.x2);
    bool bVertical = (b.x1 == b.x2);
    long long axLo = min(a.x1, a.x2), axHi = max(a.x1, a.x2);
    long long ayLo = min(a.y1, a.y2), ayHi = max(a.y1, a.y2);
    long long bxLo = min(b.x1, b.x2), bxHi = max(b.x1, b.x2);
    long long byLo = min(b.y1, b.y2), byHi = max(b.y1, b.y2);

    if (aVertical && bVertical) {
        return a.x1 == b.x1 && max(ayLo, byLo) <= min(ayHi, byHi);
    }
    if (!aVertical && !bVertical) {
        return a.y1 == b.y1 && max(axLo, bxLo) <= min(axHi, bxHi);
    }
    const Segment& v = aVertical ? a : b;
    const Segment& h = aVertical ? b : a;
    return min(h.x1, h.x2) <= v.x1 && v.x1 <= max(h.x1, h.x2) &&
           min(v.y1, v.y2) <= h.y1 && h.y1 <= max(v.y1, v.y2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> d(n);
        for (long long& x : d) cin >> x;

        vector<Segment> segments;
        long long x = 0, y = 0;
        const int dx[4] = {0, -1, 0, 1};
        const int dy[4] = {1, 0, -1, 0};
        bool crossed = false;
        for (int i = 0; i < n && !crossed; ++i) {
            long long nx = x + dx[i % 4] * d[i];
            long long ny = y + dy[i % 4] * d[i];
            Segment cur{x, y, nx, ny};
            for (int j = 0; j + 1 < i; ++j) {
                if (intersects(cur, segments[j])) {
                    crossed = true;
                    break;
                }
            }
            segments.push_back(cur);
            x = nx;
            y = ny;
        }
        cout << (crossed ? "Yes" : "No") << '\n';
    }
}
