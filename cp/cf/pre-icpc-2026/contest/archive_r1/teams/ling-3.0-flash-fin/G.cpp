#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<long long> d(n);
        for (int i = 0; i < n; i++) scanf("%lld", &d[i]);
        
        // Directions: N, W, S, E
        // Track path points
        vector<long long> px(n+1), py(n+1);
        px[0] = py[0] = 0;
        long long x = 0, y = 0;
        int dx[] = {0, -1, 0, 1};
        int dy[] = {1, 0, -1, 0};
        for (int i = 0; i < n; i++) {
            x += dx[i%4] * d[i];
            y += dy[i%4] * d[i];
            px[i+1] = x; py[i+1] = y;
        }
        
        bool intersect = false;
        // Check segment i against segments j where i-5 <= j <= i-2
        for (int i = 2; i < n && !intersect; i++) {
            for (int j = max(0, i-5); j <= i-2 && !intersect; j++) {
                // Segment i: (px[i],py[i]) to (px[i+1],py[i+1])
                // Segment j: (px[j],py[j]) to (px[j+1],py[j+1])
                long long s1x1=px[i],s1y1=py[i],s1x2=px[i+1],s1y2=py[i+1];
                long long s2x1=px[j],s2y1=py[j],s2x2=px[j+1],s2y2=py[j+1];
                
                // Skip consecutive segments
                if (j+1 == i || i+1 == j) continue;
                
                // Check intersection of two axis-aligned segments
                // Both segments are axis-aligned (one horizontal, one vertical)
                bool s1v = (s1x1 == s1x2); // segment 1 is vertical
                bool s2v = (s2x1 == s2x2); // segment 2 is vertical
                bool s1h = !s1v;
                bool s2h = !s2v;
                
                if (s1v && s2h) {
                    // s1 vertical, s2 horizontal
                    long long vx = s1x1, vy1 = min(s1y1,s1y2), vy2 = max(s1y1,s1y2);
                    long long hy = s2y1, hx1 = min(s2x1,s2x2), hx2 = max(s2x1,s2x2);
                    if (hx1 <= vx && vx <= hx2 && vy1 <= hy && hy <= vy2) intersect = true;
                } else if (s1h && s2v) {
                    long long hy = s1y1, hx1 = min(s1x1,s1x2), hx2 = max(s1x1,s1x2);
                    long long vx = s2x1, vy1 = min(s2y1,s2y2), vy2 = max(s2y1,s2y2);
                    if (hx1 <= vx && vx <= hx2 && vy1 <= hy && hy <= vy2) intersect = true;
                } else if (s1v && s2v) {
                    if (s1x1 == s2x1) {
                        long long a1 = min(s1y1,s1y2), b1 = max(s1y1,s1y2);
                        long long a2 = min(s2y1,s2y2), b2 = max(s2y1,s2y2);
                        if (max(a1,a2) <= min(b1,b2)) intersect = true;
                    }
                } else if (s1h && s2h) {
                    if (s1y1 == s2y1) {
                        long long a1 = min(s1x1,s1x2), b1 = max(s1x1,s1x2);
                        long long a2 = min(s2x1,s2x2), b2 = max(s2x1,s2x2);
                        if (max(a1,a2) <= min(b1,b2)) intersect = true;
                    }
                }
            }
        }
        
        printf("%s\n", intersect ? "Yes" : "No");
    }
    return 0;
}
