#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> prefix(n + 1);
        for (int i = 1; i <= n; ++i) {
            long long x;
            cin >> x;
            prefix[i] = prefix[i - 1] + x;
        }
        long long total = prefix[n];
        if (total == 0) {
            long long answer = 1;
            for (int i = 1; i < n; ++i)
                if (prefix[i] == 0) answer = answer * 2 % MOD;
            cout << answer << '\n';
            continue;
        }

        unordered_map<long long, vector<int>> positions;
        positions.reserve(n * 2);
        for (int i = 1; i < n; ++i) positions[prefix[i]].push_back(i);
        vector<pair<int, long long>> candidates;
        for (auto &[sum, where] : positions) {
            if (sum && total % sum == 0) {
                long long parts = total / sum;
                if (2 <= parts && parts <= n) candidates.push_back({(int)parts, sum});
            }
        }

        long long answer = 1;
        for (auto [parts, segmentSum] : candidates) {
            const vector<int> *previous = &positions[segmentSum];
            vector<int> previousWays(previous->size(), 1), currentWays;
            bool possible = true;
            for (int part = 2; part < parts; ++part) {
                auto it = positions.find(segmentSum * part);
                if (it == positions.end()) { possible = false; break; }
                const auto &current = it->second;
                currentWays.assign(current.size(), 0);
                int p = 0;
                long long running = 0;
                for (int i = 0; i < (int)current.size(); ++i) {
                    while (p < (int)previous->size() && (*previous)[p] < current[i]) {
                        running += previousWays[p++];
                        if (running >= MOD) running -= MOD;
                    }
                    currentWays[i] = running;
                }
                previous = &it->second;
                previousWays.swap(currentWays);
            }
            if (possible)
                for (int ways : previousWays) answer = (answer + ways) % MOD;
        }
        cout << answer << '\n';
    }
}
