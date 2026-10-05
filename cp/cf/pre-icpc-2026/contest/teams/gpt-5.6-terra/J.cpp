#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> pref(n + 1);
        map<long long, vector<int>> where;
        where[0].push_back(0);
        for (int i = 1; i <= n; ++i) {
            long long x;
            cin >> x;
            pref[i] = pref[i - 1] + x;
            where[pref[i]].push_back(i);
        }
        long long total = pref[n];
        if (total == 0) {
            long long ans = 1;
            for (int i = 1; i < n; ++i) if (pref[i] == 0) ans = ans * 2 % MOD;
            cout << ans << '\n';
            continue;
        }
        long long ans = 0;
        for (int parts = 1; parts <= n; ++parts) {
            if (total % parts) continue;
            long long need = total / parts;
            if (parts == 1) {
                ++ans;
                continue;
            }
            vector<int> previous;
            vector<long long> ways;
            for (int j = 1; j < parts; ++j) {
                auto it = where.find(need * j);
                if (it == where.end()) break;
                vector<long long> next(it->second.size());
                if (j == 1) {
                    fill(next.begin(), next.end(), 1);
                } else {
                    long long sum = 0;
                    int p = 0;
                    for (int i = 0; i < (int)it->second.size(); ++i) {
                        while (p < (int)previous.size() && previous[p] < it->second[i])
                            sum = (sum + ways[p++]) % MOD;
                        next[i] = sum;
                    }
                }
                previous = it->second;
                ways = move(next);
                if (j == parts - 1) {
                    for (long long count : ways) ans = (ans + count) % MOD;
                }
            }
        }
        cout << ans % MOD << '\n';
    }
}
