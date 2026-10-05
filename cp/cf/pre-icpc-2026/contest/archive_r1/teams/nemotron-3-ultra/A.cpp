#include <bits/stdc++.h>
using namespace std;

vector<int> build_sa_naive(const string& s) {
    int n = s.size();
    vector<int> sa(n);
    iota(sa.begin(), sa.end(), 0);
    sort(sa.begin(), sa.end(), [&](int i, int j) {
        return s.substr(i) < s.substr(j);
    });
    return sa;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<int> sa(n);
    for (int i = 0; i < n; ++i) {
        cin >> sa[i];
        --sa[i];
    }
    
    vector<int> rank(n);
    for (int i = 0; i < n; ++i) {
        rank[sa[i]] = i;
    }
    
    // Determine strict constraints between adjacent SA elements
    vector<int> weight(n - 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u = sa[i], v = sa[i + 1];
        bool strict = false;
        if (v == n - 1) {
            strict = true; // v is last position, u is not (since permutation)
        } else if (u != n - 1) {
            // both have next character
            if (rank[u + 1] > rank[v + 1]) strict = true;
        }
        // if u == n-1 (u is last), non-strict
        weight[i] = strict ? 1 : 0;
    }
    
    // Assign characters greedily in SA order
    vector<int> char_at(n);
    char_at[sa[0]] = 1;
    for (int i = 1; i < n; ++i) {
        char_at[sa[i]] = char_at[sa[i - 1]] + weight[i - 1];
    }
    
    int max_char = *max_element(char_at.begin(), char_at.end());
    
    // Build string
    string s;
    for (int i = 0; i < n; ++i) {
        s.push_back('a' + char_at[i] - 1);
    }
    
    // Verify
    vector<int> computed_sa = build_sa_naive(s);
    if (computed_sa == sa) {
        cout << max_char << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}