#include <bits/stdc++.h>
using namespace std;

bool onSegment(pair<long long, long long> p, pair<long long, long long> q, pair<long long, long long> r) {
    return min(q.first, r.first) <= p.first && p.first <= max(q.first, r.first) &&
           min(q.second, r.second) <= p.second && p.second <= max(q.second, r.second);
}

long long cross(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

bool intersect(pair<long long, long long> p1, pair<long long, long long> p2,
               pair<long long, long long> p3, pair<long long, long long> p4) {
    long long o1 = cross(p1, p2, p3);
    long long o2 = cross(p1, p2, p4);
    long long o3 = cross(p3, p4, p1);
    long long o4 = cross(p3, p4, p2);
    
    if (o1 == 0 && onSegment(p3, p1, p2)) return true;
    if (o2 == 0 && onSegment(p4, p1, p2)) return true;
    if (o3 == 0 && onSegment(p1, p3, p4)) return true;
    if (o4 == 0 && onSegment(p2, p3, p4)) return true;
    
    return (o1 > 0) != (o2 > 0) && (o3 > 0) != (o4 > 0);
}

bool isSelfCrossing(vector<long long>& d) {
    int n = d.size();
    vector<pair<long long, long long>> pos(n + 1);
    pos[0] = {0, 0};
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    int dir = 0;
    for (int i = 0; i < n; i++) {
        pos[i + 1] = {pos[i].first + dx[dir] * d[i], pos[i].second + dy[dir] * d[i]};
        dir = (dir + 1) % 4;
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = max(1, i - 5); j <= i - 2; j++) {
            if (intersect(pos[j - 1], pos[j], pos[i - 1], pos[i])) {
                return true;
            }
        }
    }
    return false;
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
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        
        if (isSelfCrossing(d)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}