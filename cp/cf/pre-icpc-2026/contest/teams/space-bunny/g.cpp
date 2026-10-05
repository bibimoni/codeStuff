#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Ev { ll x; int type, idx; };
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        vector<ll> d(n);
        for (int i = 0; i < n; i++) scanf("%lld", &d[i]);
        vector<ll> x0(n), y0(n), x1(n), y1(n);
        ll x = 0, y = 0;
        vector<int> vert;
        for (int i = 0; i < n; i++) {
            ll nx = x, ny = y;
            if (i % 4 == 0) ny = y + d[i];
            else if (i % 4 == 1) nx = x - d[i];
            else if (i % 4 == 2) ny = y - d[i];
            else nx = x + d[i];
            x0[i] = x; y0[i] = y; x1[i] = nx; y1[i] = ny;
            if (i % 2 == 0) vert.push_back(i);
            x = nx; y = ny;
        }
        bool inter = false;
        auto overlap = [&](vector<array<ll, 3>> &s2) -> bool {
            sort(s2.begin(), s2.end());
            ll best = LLONG_MIN, cur = LLONG_MIN;
            for (auto &e : s2) {
                if (e[0] != cur) { cur = e[0]; best = LLONG_MIN; }
                if (e[1] <= best) return true;
                best = max(best, e[2]);
            }
            return false;
        };
        {
            vector<array<ll, 3>> s2;
            for (int i : vert) s2.push_back({x0[i], min(y0[i], y1[i]), max(y0[i], y1[i])});
            inter = overlap(s2);
        }
        if (!inter) {
            vector<array<ll, 3>> s2;
            for (int i = 0; i < n; i++) if (i % 2 == 1) s2.push_back({y0[i], min(x0[i], x1[i]), max(x0[i], x1[i])});
            inter = overlap(s2);
        }
        // perpendicular: sweep
        if (!inter) {
            vector<Ev> ev;
            ev.reserve(2 * n);
            for (int i = 0; i < n; i++) {
                if (i % 2 == 1) {
                    ll xl = min(x0[i], x1[i]), xr = max(x0[i], x1[i]);
                    ev.push_back({xl, 0, i});
                    ev.push_back({xr, 2, i});
                } else {
                    ev.push_back({x0[i], 1, i});
                }
            }
            sort(ev.begin(), ev.end(), [](const Ev &a, const Ev &b) {
                if (a.x != b.x) return a.x < b.x;
                return a.type < b.type;
            });
            set<pair<ll, int>> act;
            for (auto &e : ev) {
                if (e.type == 0) act.insert({y0[e.idx], e.idx});
                else if (e.type == 2) act.erase({y0[e.idx], e.idx});
                else {
                    int i = e.idx;
                    ll yl = min(y0[i], y1[i]), yh = max(y0[i], y1[i]);
                    auto it = act.lower_bound({yl, -1});
                    while (it != act.end() && it->first <= yh) {
                        if (abs(it->second - i) != 1) { inter = true; break; }
                        ++it;
                    }
                    if (inter) break;
                }
            }
        }
        printf("%s\n", inter ? "Yes" : "No");
    }
    return 0;
}
