#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, s;
    DSU() {}
    DSU(int n) { init(n); }
    void init(int n) { p.resize(n); s.assign(n,1); iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x]==x?x:p[x]=find(p[x]); }
    // true if merged
    bool unite(int a, int b) {
        a=find(a); b=find(b);
        if (a==b) return false;
        if (s[a]<s[b]) swap(a,b);
        p[b]=a; s[a]+=s[b];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    const int dr[4] = {-1,0,1,0};
    const int dc[4] = {0,1,0,-1};
    const int bit[4] = {1,2,4,8};
    const int opp[4] = {2,3,0,1}; // opposite dir index: U<->D? U=0,D=2; R=1,L=3
    while (T--) {
        int n, m;
        cin >> n >> m;
        int N = n*m;
        vector<int> g(N);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) cin >> g[i*m+j];
        int q;
        cin >> q;
        vector<int> imp(q);
        vector<char> destroyed(N, 0);
        for (int i = 0; i < q; i++) {
            int r,c; cin >> r >> c; --r; --c;
            imp[i] = r*m+c;
            destroyed[r*m+c] = 1;
        }
        auto id = [&](int r,int c){ return r*m+c; };
        DSU dsu(N);
        vector<char> active(N, 0);
        long long V=0,E=0,C=0;
        for (int r = 0; r < n; r++) for (int c = 0; c < m; c++) {
            int v = id(r,c);
            if (g[v]==0 || destroyed[v]) continue;
            active[v]=1; V++; C++;
            // only right(1) and down(2) to count each edge once
            for (int d : {1,2}) {
                int nr=r+dr[d], nc=c+dc[d];
                if (nr<0||nr>=n||nc<0||nc>=m) continue;
                int u=id(nr,nc);
                if (g[u]==0 || destroyed[u]) continue;
                if ((g[v]&bit[d]) && (g[u]&bit[opp[d]])) {
                    E++;
                    if (dsu.unite(v,u)) C--;
                }
            }
        }
        vector<long long> res(q);
        if (q > 0) res[q-1] = E - V + C;
        for (int i = q-1; i >= 1; i--) {
            int v = imp[i];
            int r = v/m, c = v%m;
            active[v]=1; V++; C++;
            for (int d = 0; d < 4; d++) {
                int nr=r+dr[d], nc=c+dc[d];
                if (nr<0||nr>=n||nc<0||nc>=m) continue;
                int u=id(nr,nc);
                if (!active[u]) continue;
                if ((g[v]&bit[d]) && (g[u]&bit[opp[d]])) {
                    E++;
                    if (dsu.unite(v,u)) C--;
                }
            }
            res[i-1] = E - V + C;
        }
        for (int i = 0; i < q; i++) {
            if (i) cout << ' ';
            cout << res[i];
        }
        cout << '\n';
    }
    return 0;
}
