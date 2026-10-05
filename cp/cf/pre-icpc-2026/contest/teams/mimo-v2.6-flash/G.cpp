#include <bits/stdc++.h>
using namespace std;

struct Seg { long long fixed; long long lo, hi; int idx; }; // H: fixed=y, lo/hi=x; V: fixed=x, lo/hi=y

int main() {
    int t; scanf("%d", &t);
    string out;
    out.reserve(1 << 20);
    while (t--) {
        int n; scanf("%d", &n);
        vector<long long> d(n);
        for (int i = 0; i < n; i++) scanf("%lld", &d[i]);
        // build segments
        vector<long long> px(n + 1), py(n + 1);
        px[0] = py[0] = 0;
        for (int i = 0; i < n; i++) {
            int dir = i % 4; // 0 N, 1 W, 2 S, 3 E
            long long dx = 0, dy = 0;
            if (dir == 0) dy = d[i];
            else if (dir == 1) dx = -d[i];
            else if (dir == 2) dy = -d[i];
            else dx = d[i];
            px[i + 1] = px[i] + dx;
            py[i + 1] = py[i] + dy;
        }
        vector<Seg> H, V;
        H.reserve(n / 2 + 1); V.reserve(n / 2 + 1);
        for (int i = 1; i <= n; i++) {
            int dir = (i - 1) % 4;
            if (dir == 1 || dir == 3) { // horizontal
                H.push_back({py[i], min(px[i - 1], px[i]), max(px[i - 1], px[i]), i});
            } else {
                V.push_back({px[i], min(py[i - 1], py[i]), max(py[i - 1], py[i]), i});
            }
        }
        bool found = false;

        // 1) HV sweep
        {
            struct Ev { long long x; int type; int idx; };
            vector<Ev> ev;
            ev.reserve(H.size() * 2 + V.size());
            for (int i = 0; i < (int)H.size(); i++) {
                ev.push_back({H[i].lo, 0, i});
                ev.push_back({H[i].hi, 2, i});
            }
            for (int i = 0; i < (int)V.size(); i++) ev.push_back({V[i].fixed, 1, i});
            sort(ev.begin(), ev.end(), [](const Ev& a, const Ev& b) {
                if (a.x != b.x) return a.x < b.x;
                return a.type < b.type;
            });
            map<long long, set<int>> active;
            for (auto& e : ev) {
                if (found) break;
                if (e.type == 0) {
                    active[H[e.idx].fixed].insert(H[e.idx].idx);
                } else if (e.type == 2) {
                    auto it = active.find(H[e.idx].fixed);
                    if (it != active.end()) {
                        it->second.erase(H[e.idx].idx);
                        if (it->second.empty()) active.erase(it);
                    }
                } else {
                    const Seg& v = V[e.idx];
                    int vi = v.idx;
                    auto it = active.lower_bound(v.lo);
                    int examined = 0;
                    while (it != active.end() && it->first <= v.hi && examined < 4) {
                        for (int hi : it->second) {
                            examined++;
                            if (abs(hi - vi) != 1) { found = true; break; }
                            if (examined >= 4) break;
                        }
                        if (found) break;
                        ++it;
                    }
                }
            }
        }

        // 2) H-H same y overlap
        if (!found) {
            map<long long, vector<array<long long, 3>>> g; // y -> {x1, x2, idx}
            for (auto& s : H) g[s.fixed].push_back({s.lo, s.hi, s.idx});
            for (auto& kv : g) {
                auto& v = kv.second;
                sort(v.begin(), v.end());
                long long maxx2 = LLONG_MIN;
                for (auto& seg : v) {
                    if (maxx2 >= seg[0]) { found = true; break; } // touch counts
                    maxx2 = max(maxx2, seg[1]);
                }
                if (found) break;
            }
        }

        // 3) V-V same x overlap
        if (!found) {
            map<long long, vector<array<long long, 3>>> g;
            for (auto& s : V) g[s.fixed].push_back({s.lo, s.hi, s.idx});
            for (auto& kv : g) {
                auto& v = kv.second;
                sort(v.begin(), v.end());
                long long maxy2 = LLONG_MIN;
                for (auto& seg : v) {
                    if (maxy2 >= seg[0]) { found = true; break; }
                    maxy2 = max(maxy2, seg[1]);
                }
                if (found) break;
            }
        }

        out += found ? "Yes\n" : "No\n";
    }
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
