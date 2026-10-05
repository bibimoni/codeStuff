#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3000;
bitset<MAXN> A[MAXN], P[MAXN], CB[MAXN];
int pivrow[MAXN], pivcol[MAXN];

int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);
    for (int i = 0; i < N; i++) {
        A[i].reset(); A[i].set(i);
        P[i].reset(); P[i].set(i);
        pivrow[i] = -1;
    }
    for (int e = 0; e < M; e++) {
        int u, v; scanf("%d %d", &u, &v); u--; v--;
        A[u].set(v); A[v].set(u);
    }
    int rank = 0;
    for (int c = 0, r = 0; c < N && r < N; c++) {
        int piv = -1;
        for (int i = r; i < N; i++) if (A[i][c]) { piv = i; break; }
        if (piv < 0) continue;
        if (piv != r) { swap(A[r], A[piv]); swap(P[r], P[piv]); }
        for (int i = r + 1; i < N; i++) if (A[i][c]) { A[i] ^= A[r]; P[i] ^= P[r]; }
        pivrow[c] = r; pivcol[r] = c;
        r++; rank = r;
    }
    for (int r = 0; r < rank; r++)
        for (int c = 0; c < N; c++)
            if (A[r][c]) CB[c].set(r);

    string out;
    out.reserve(1 << 22);
    for (int q = 0; q < Q; q++) {
        bitset<MAXN> b;
        for (int i = 0; i < N; i++) {
            int ch;
            do { ch = getchar(); } while (ch != '0' && ch != '1');
            if (ch == '0') b.set(i);
        }
        bitset<MAXN> pb;
        for (int r = 0; r < N; r++)
            if (((P[r] & b).count() & 1) != 0) pb.set(r);
        bool ok = true;
        for (int r = rank; r < N; r++) if (pb[r]) { ok = false; break; }
        if (!ok) { out += "-1\n"; continue; }
        bitset<MAXN> x;
        for (int r = rank - 1; r >= 0; r--) {
            if (pb[r]) {
                int c = pivcol[r];
                x.set(c);
                pb ^= CB[c];
            }
        }
        out += to_string((int)x.count());
        for (int i = 0; i < N; i++) if (x[i]) { out += ' '; out += to_string(i + 1); }
        out += '\n';
    }
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
