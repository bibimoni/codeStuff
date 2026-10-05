#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)4e18;

struct Node { ll mnA, mnV, mnPair, lazyA, lazyV; };

// n, per-testcase
int n;
vector<Node> tr;
vector<ll> bit, bArr;

// P[i] = a_1 + ... + a_{i-1};  A[i] = P[i] + b[i];  V[i] = b[i] - P[i]
// TOT   = P[n+1] = sum a_i

void pull(int v){
    Node &o = tr[v]; Node &L = tr[2*v], &R = tr[2*v+1];
    o.mnA = min(L.mnA, R.mnA);
    o.mnV = min(L.mnV, R.mnV);
    // minPair = min_{i<j} A[i] + V[j]; the cross term needs i left of j
    o.mnPair = min({L.mnPair, R.mnPair, L.mnA + R.mnV});
}
void apply(int v, ll dA, ll dV){
    Node &o = tr[v];
    o.mnA += dA; o.mnV += dV;
    if(o.mnPair < INF/2) o.mnPair += dA + dV;   // singleton nodes keep INF
    o.lazyA += dA; o.lazyV += dV;
}
void push(int v){
    if(tr[v].lazyA || tr[v].lazyV){
        apply(2*v, tr[v].lazyA, tr[v].lazyV);
        apply(2*v+1, tr[v].lazyA, tr[v].lazyV);
        tr[v].lazyA = tr[v].lazyV = 0;
    }
}
void build(int v, int l, int r, const vector<ll> &PA){
    tr[v].lazyA = tr[v].lazyV = 0;
    if(l == r){
        tr[v].mnA = PA[l] + bArr[l];
        tr[v].mnV = bArr[l] - PA[l];
        tr[v].mnPair = INF;
        return;
    }
    int m = (l+r)/2;
    build(2*v, l, m, PA); build(2*v+1, m+1, r, PA);
    pull(v);
}
void rangeAdd(int v,int l,int r,int ql,int qr,ll dA,ll dV){
    if(ql > qr || r < ql || qr < l) return;      // empty / disjoint
    if(ql <= l && r <= qr){ apply(v,dA,dV); return; }
    push(v);
    int m = (l+r)/2;
    if(ql <= m) rangeAdd(2*v, l, m, ql, qr, dA, dV);
    if(qr >  m) rangeAdd(2*v+1, m+1, r, ql, qr, dA, dV);
    pull(v);
}
// minA, minV, and order-aware min_{i<j}(A[i]+V[j]) over [ql,qr]
struct Agg { ll mnA, mnV, mnPair; };
Agg queryAgg(int v,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return {tr[v].mnA, tr[v].mnV, tr[v].mnPair};
    push(v);
    int m = (l+r)/2;
    if(qr <= m) return queryAgg(2*v, l, m, ql, qr);
    if(ql >  m) return queryAgg(2*v+1, m+1, r, ql, qr);
    Agg L = queryAgg(2*v, l, m, ql, qr), R = queryAgg(2*v+1, m+1, r, ql, qr);
    return { min(L.mnA, R.mnA), min(L.mnV, R.mnV),
             min({L.mnPair, R.mnPair, L.mnA + R.mnV}) };
}
ll qA (int l,int r){ if(l > r) return INF; return queryAgg(1,1,n,l,r).mnA; }
ll qV (int l,int r){ if(l > r) return INF; return queryAgg(1,1,n,l,r).mnV; }
ll qPair(int l,int r){ if(l >= r) return INF; return queryAgg(1,1,n,l,r).mnPair; }

// Fenwick over a[]: P[i] = bitSum(i-1), TOT = bitSum(n)
void bitAdd(int x,ll d){ for(; x <= n; x += x&-x) bit[x] += d; }
ll bitSum(int x){ ll s = 0; for(; x > 0; x -= x&-x) s += bit[x]; return s; }
ll P(int i){ return bitSum(i-1); }

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--){
        int q; cin >> n >> q;
        vector<ll> a(n+1), PA(n+1);
        bArr.assign(n+1, 0);
        bit.assign(n+1, 0);
        for(int i = 1; i <= n; i++){ cin >> a[i]; bit[i] = a[i]; }
        for(int i = 1; i <= n; i++) cin >> bArr[i];
        for(int i = 1; i <= n; i++){ if(i > 1) bit[i] += bit[i-1]; }  // prefix into bit
        { ll acc = 0; for(int i = 1; i <= n; i++){ PA[i] = acc; acc += a[i]; } }
        tr.assign(4*n + 5, Node());
        build(1, 1, n, PA);
        // rebuild BIT as a Fenwick from the prefix array
        for(int i = 1; i <= n; i++) bit[i] = a[i];
        for(int i = 1; i <= n; i++){ int j = i + (i & -i); if(j <= n) bit[j] += bit[i]; }

        for(int it = 0; it < q; it++){
            int type; cin >> type;
            if(type == 1){
                int s, t; cin >> s >> t;
                ll Ps = P(s), T = bitSum(n);
                ll ans = INF;
                if(t == n+1){
                    ans = min(ans, bArr[s]);
                    ans = min(ans, qA(s+1, n) - Ps);
                    ans = min(ans, qV(1, s-1) + Ps);
                    ans = min(ans, qV(s+1, n) + Ps + T);
                    ans = min(ans, qA(1, s-1) + T - Ps);
                } else {
                    ll Pt = P(t), D = Pt - Ps;
                    ans = min(ans, min(D, T - D));
                    ans = min(ans, qPair(s, t) + D);
                    ans = min(ans, qA(s, t-1) + qA(1, s-1) + T - Ps - Pt);
                    ans = min(ans, qA(s, t-1) + qA(t+1, n) - Ps - Pt);
                    ans = min(ans, qV(1, s-1) + qV(s+1, t) + Ps + Pt);
                    ans = min(ans, qV(t+1, n) + qV(s+1, t) + T + Ps + Pt);
                    ans = min(ans, qV(1, s-1) + qA(t+1, n) + Ps - Pt);
                    ans = min(ans, qPair(1, s-1) + T + Ps - Pt);
                    ans = min(ans, qPair(t+1, n) + T + Ps - Pt);
                }
                cout << ans << "\n";
            } else if(type == 2){
                int x; ll w; cin >> x >> w;
                ll d = w - a[x]; a[x] = w;
                rangeAdd(1, 1, n, x+1, n, d, -d);   // P[i] += d for i > x
                bitAdd(x, d);
            } else {
                int x; ll w; cin >> x >> w;
                ll d = w - bArr[x]; bArr[x] = w;
                rangeAdd(1, 1, n, x, x, d, d);      // A[x], V[x] both += d
            }
        }
    }
    return 0;
}
