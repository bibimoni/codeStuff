#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    int width = n + q, words = (width + 63) / 64;
    vector<vector<unsigned long long>> a(n, vector<unsigned long long>(words));
    auto set_bit = [&](int row, int col) { a[row][col >> 6] |= 1ULL << (col & 63); };
    auto bit = [&](int row, int col) { return (a[row][col >> 6] >> (col & 63)) & 1ULL; };
    for (int i = 0; i < n; ++i) set_bit(i, i);
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        set_bit(u, v);
        set_bit(v, u);
    }
    for (int z = 0; z < q; ++z)
        for (int i = 0; i < n; ++i) {
            char state;
            cin >> state;
            if (state == '0') set_bit(i, n + z);
        }

    vector<int> pivot(n, -1);
    int row = 0;
    for (int col = 0; col < n; ++col) {
        int pick = row;
        while (pick < n && !bit(pick, col)) ++pick;
        if (pick == n) continue;
        swap(a[row], a[pick]);
        pivot[col] = row;
        for (int r = 0; r < n; ++r) if (r != row && bit(r, col))
            for (int w = col >> 6; w < words; ++w) a[r][w] ^= a[row][w];
        ++row;
    }
    vector<bool> possible(q, true);
    for (int r = row; r < n; ++r)
        for (int z = 0; z < q; ++z)
            if (bit(r, n + z)) possible[z] = false;
    for (int z = 0; z < q; ++z) {
        if (!possible[z]) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> answer;
        for (int col = 0; col < n; ++col)
            if (pivot[col] != -1 && bit(pivot[col], n + z)) answer.push_back(col + 1);
        cout << answer.size();
        for (int x : answer) cout << ' ' << x;
        cout << '\n';
    }
}
