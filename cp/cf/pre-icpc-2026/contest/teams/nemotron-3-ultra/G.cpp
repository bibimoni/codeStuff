#include <bits/stdc++.h>
using namespace std;

struct Segment {
    long long x1, y1, x2, y2;
    // normalized: x1 <= x2, y1 <= y2
};

bool intersect(const Segment& a, const Segment& b) {
    // a: (x1,y1)-(x2,y2), b: (x3,y3)-(x4,y4)
    // normalized
    if (a.y1 == a.y2 && b.y1 == b.y2) { // both horizontal
        if (a.y1 != b.y1) return false;
        return max(a.x1, b.x1) <= min(a.x2, b.x2);
    }
    if (a.x1 == a.x2 && b.x1 == b.x2) { // both vertical
        if (a.x1 != b.x1) return false;
        return max(a.y1, b.y1) <= min(a.y2, b.y2);
    }
    // one horizontal, one vertical
    const Segment *h, *v;
    if (a.y1 == a.y2) { h = &a; v = &b; }
    else { h = &b; v = &a; }
    // h: horizontal, v: vertical
    return (v->x1 >= h->x1 && v->x1 <= h->x2) &&
           (h->y1 >= v->y1 && h->y1 <= v->y2);
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
        for (int i = 0; i < n; ++i) cin >> d[i];
        
        vector<Segment> segs;
        segs.reserve(n);
        long long x = 0, y = 0;
        bool found = false;
        
        for (int i = 0; i < n && !found; ++i) {
            long long nx = x, ny = y;
            if (i % 4 == 0) ny += d[i];      // N
            else if (i % 4 == 1) nx -= d[i];  // W
            else if (i % 4 == 2) ny -= d[i];  // S
            else nx += d[i];                   // E
            
            Segment cur = {min(x, nx), min(y, ny), max(x, nx), max(y, ny)};
            
            // Check against previous non-adjacent segments (up to i-6)
            for (int j = max(0, i - 6); j <= i - 2; ++j) {
                if (intersect(cur, segs[j])) {
                    found = true;
                    break;
                }
            }
            
            segs.push_back(cur);
            x = nx;
            y = ny;
        }
        
        cout << (found ? "Yes" : "No") << '\n';
    }
    return 0;
}