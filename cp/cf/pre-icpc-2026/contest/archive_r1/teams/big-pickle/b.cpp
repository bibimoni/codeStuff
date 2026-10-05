#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long u64;
static char buf[1 << 16];
static int bl = 0, bp = 0;
static inline int gc() {
    if (bp == bl) { bl = (int)fread(buf, 1, sizeof(buf), stdin); bp = 0; if (!bl) return -1; }
    return buf[bp++];
}
static inline long long readInt() {
    int c = gc(); while (c != -1 && (c < '0' || c > '9') && c != '-') c = gc();
    bool neg = false; if (c == '-') { neg = true; c = gc(); }
    long long v = 0;
    while (c >= '0' && c <= '9') { v = v * 10 + (c - '0'); c = gc(); }
    return neg ? -v : v;
}
int main() {
    int N = (int)readInt(), M = (int)readInt(), Q = (int)readInt();
    int NP = (N + 63) / 64 * 64, HW = NP / 64, RW = HW, W = 2 * HW;
    vector<u64> A((size_t)N * W, 0);
    auto setbit = [&](int r, int c) { A[(size_t)r * W + (c >> 6)] |= 1ULL << (c & 63); };
    for (int i = 0; i < N; i++) { setbit(i, i); setbit(i, NP + i); }
    for (int i = 0; i < M; i++) {
        int u = (int)readInt() - 1, v = (int)readInt() - 1;
        setbit(u, v); setbit(v, u);
    }
    // Gauss-Jordan on [A | I]
    vector<int> pivotRow(N, -1);
    vector<int> rowOf; rowOf.reserve(N);
    for (int col = 0; col < N; col++) {
        int pr = -1;
        for (int r = col; r < N; r++)
            if (A[(size_t)r * W + (col >> 6)] >> (col & 63) & 1) { pr = r; break; }
        if (pr < 0) continue;
        if (pr != col)
            for (int w = 0; w < W; w++) swap(A[(size_t)pr * W + w], A[(size_t)col * W + w]);
        pivotRow[col] = col;
        u64 *pc = &A[(size_t)col * W];
        int w0 = col >> 6;
        for (int r = 0; r < N; r++) {
            if (r == col) continue;
            u64 *rp = &A[(size_t)r * W];
            if (!((rp[w0] >> (col & 63)) & 1)) continue;
            for (int w = w0; w < W; w++) rp[w] ^= pc[w];
        }
    }
    // free rows = rows whose A part is all zero
    vector<int> freeRows;
    for (int r = 0; r < N; r++) {
        bool empty = true;
        for (int w = 0; w < HW; w++) if (A[(size_t)r * W + w]) { empty = false; break; }
        if (empty) freeRows.push_back(r);
    }
    string out;
    vector<u64> b(HW), y(N);
    for (int qi = 0; qi < Q; qi++) {
        fill(b.begin(), b.end(), 0);
        for (int i = 0; i < N; i++) {
            int c = gc();
            while (c != '0' && c != '1') c = gc();
            if (c == '0') b[i >> 6] |= 1ULL << (i & 63); // need to toggle -> bit set means "flip"
        }
        // y = T * b   (right half of the transformed matrix)
        for (int r = 0; r < N; r++) {
            const u64 *tr = &A[(size_t)r * W + RW];
            int par = 0;
            for (int w = 0; w < HW; w++) par ^= __builtin_parityll(tr[w] & b[w]);
            y[r] = par;
        }
        bool ok = true;
        for (int r : freeRows) if (y[r]) { ok = false; break; }
        if (!ok) { out += "-1\n"; continue; }
        vector<int> sol(N, 0);
        for (int col = 0; col < N; col++) if (pivotRow[col] >= 0) sol[col] = y[pivotRow[col]];
        int k = 0;
        for (int i = 0; i < N; i++) k += sol[i];
        out += to_string(k);
        for (int i = 0; i < N; i++) if (sol[i]) { out += ' '; out += to_string(i + 1); }
        out += '\n';
    }
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
