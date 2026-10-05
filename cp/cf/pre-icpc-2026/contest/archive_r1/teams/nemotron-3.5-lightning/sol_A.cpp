#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> sa(n);
    for (int i = 0; i < n; i++) {
        cin >> sa[i];
        sa[i]--; // 0-indexed
    }

    vector<int> rank(n);
    for (int i = 0; i < n; i++) {
        rank[sa[i]] = i;
    }

    int strict_count = 0;
    for (int i = 0; i < n - 1; i++) {
        int a = sa[i];
        int b = sa[i + 1];
        if (a == n - 1) {
            // sa[i] is the last position, no strict inequality needed
            // suffix at n-1 is just s[n-1], and it's smaller if s[n-1] <= s[b]
            continue;
        }
        if (b == n - 1) {
            // sa[i+1] is the last position, strict inequality forced
            strict_count++;
            continue;
        }
        if (rank[a + 1] > rank[b + 1]) {
            // forced strict inequality
            strict_count++;
        }
    }

    int ans = strict_count + 1;
    cout << ans << "\n";
    return 0;
}