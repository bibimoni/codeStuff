#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    int cw = (n + 63) / 64, qw = (q + 63) / 64;
    vector<ull> a((size_t)n * cw), rhs((size_t)n * qw);
    auto A = [&](int r, int w) -> ull& { return a[(size_t)r * cw + w]; };
    auto R = [&](int r, int w) -> ull& { return rhs[(size_t)r * qw + w]; };
    for (int i = 0; i < n; ++i) A(i, i / 64) |= 1ULL << (i % 64);
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        A(u, v / 64) |= 1ULL << (v % 64);
        A(v, u / 64) |= 1ULL << (u % 64);
    }
    for (int query = 0; query < q; ++query) {
        for (int i = 0; i < n; ++i) {
            char state;
            cin >> state;
            if (state == '0') R(i, query / 64) |= 1ULL << (query % 64);
        }
    }

    vector<int> pivot;
    int rank = 0;
    for (int col = 0; col < n; ++col) {
        int row = rank;
        while (row < n && !(A(row, col / 64) >> (col % 64) & 1)) ++row;
        if (row == n) continue;
        for (int w = 0; w < cw; ++w) swap(A(rank, w), A(row, w));
        for (int w = 0; w < qw; ++w) swap(R(rank, w), R(row, w));
        for (int i = rank + 1; i < n; ++i) if (A(i, col / 64) >> (col % 64) & 1) {
            for (int w = col / 64; w < cw; ++w) A(i, w) ^= A(rank, w);
            for (int w = 0; w < qw; ++w) R(i, w) ^= R(rank, w);
        }
        pivot.push_back(col);
        ++rank;
    }

    vector<ull> bad(qw), x((size_t)n * qw);
    for (int i = rank; i < n; ++i)
        for (int w = 0; w < qw; ++w) bad[w] |= R(i, w);
    auto X = [&](int var, int w) -> ull& { return x[(size_t)var * qw + w]; };
    for (int row = rank - 1; row >= 0; --row) {
        int col = pivot[row];
        for (int w = 0; w < qw; ++w) X(col, w) = R(row, w);
        for (int aw = col / 64; aw < cw; ++aw) {
            ull bits = A(row, aw);
            if (aw == col / 64)
                bits &= col % 64 == 63 ? 0 : ~((1ULL << (col % 64 + 1)) - 1);
            while (bits) {
                int bit = __builtin_ctzll(bits);
                int other = aw * 64 + bit;
                if (other < n)
                    for (int w = 0; w < qw; ++w) X(col, w) ^= X(other, w);
                bits &= bits - 1;
            }
        }
    }

    for (int query = 0; query < q; ++query) {
        ull mask = 1ULL << (query % 64);
        if (bad[query / 64] & mask) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> answer;
        for (int i = 0; i < n; ++i)
            if (X(i, query / 64) & mask) answer.push_back(i + 1);
        cout << answer.size();
        for (int v : answer) cout << ' ' << v;
        cout << '\n';
    }
}
