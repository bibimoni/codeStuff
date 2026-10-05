#include <bits/stdc++.h>
using namespace std;

int count_inv(const vector<int>& p) {
    int c = 0;
    for (int i = 0; i < (int)p.size(); ++i)
        for (int j = i+1; j < (int)p.size(); ++j)
            if (p[i] > p[j]) ++c;
    return c;
}

int main() {
    for (int n = 1; n <= 8; ++n) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        map<int, vector<vector<int>>> by_inv;
        do {
            by_inv[count_inv(p)].push_back(p);
        } while (next_permutation(p.begin(), p.end()));
        
        for (auto& [m, perms] : by_inv) {
            for (int k = 1; k <= (int)perms.size() + 1; ++k) {
                // Run our algorithm
                // Need to replicate the DP and construction
            }
        }
    }
    return 0;
}
