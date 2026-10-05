// C - Cave of Countless Chambers (interactive)
// Leftmost descent gives depth h (2^h <= N < 2^(h+1)); last level has c nodes,
// all leftmost, so N = 2^h - 1 + c. Binary search c with path-cached navigation.
#include <bits/stdc++.h>
using namespace std;
long long qc = 0;
string cur;                        // path from root to current chamber

int ask(char d) {
    cout << "? " << d << endl;     // endl flushes
    int r;
    if (!(cin >> r)) exit(0);
    qc++;
    if (r) { if (d != 'B') cur.push_back(d); else if (!cur.empty()) cur.pop_back(); }
    return r;
}
bool goTo(const string &p) {       // navigate to p; false if some move failed
    size_t lcp = 0;
    while (lcp < cur.size() && lcp < p.size() && cur[lcp] == p[lcp]) lcp++;
    while (cur.size() > lcp) ask('B');
    for (size_t i = lcp; i < p.size(); i++) if (!ask(p[i])) return false;
    return true;
}
string pathOf(long long v) {       // v >= 1 heap-indexed: path = bits below the MSB
    string p;
    long long top = 1;
    while ((top << 1) <= v) top <<= 1;
    for (top >>= 1; top; top >>= 1) p.push_back((v & top) ? 'R' : 'L');
    return p;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        cur.clear();
        long long h = 0;
        while (ask('L')) h++;                   // deepest node on the leftmost chain
        long long base = 1LL << h;
        long long lo = 0, hi = base;            // node base+x exists iff x <= lo
        while (hi - lo > 1) {
            long long mid = lo + (hi - lo) / 2;
            bool ex = goTo(pathOf(base + mid));
            if (ex) lo = mid; else hi = mid;
        }
        long long N = base - 1 + lo + 1;
        cout << "! " << N << endl;
        if (qc > 8000) { /* keep counting only for diagnostics */ }
    }
}
