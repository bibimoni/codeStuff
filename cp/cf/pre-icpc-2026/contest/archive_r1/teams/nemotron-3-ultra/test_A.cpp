#include <bits/stdc++.h>
using namespace std;

vector<int> build_sa(const string& s) {
    int n = s.size();
    vector<int> sa(n), rank(n), tmp(n);
    for (int i = 0; i < n; ++i) {
        sa[i] = i;
        rank[i] = s[i];
    }
    for (int k = 1; k < n; k <<= 1) {
        auto cmp = [&](int i, int j) {
            if (rank[i] != rank[j]) return rank[i] < rank[j];
            int ri = i + k < n ? rank[i + k] : -1;
            int rj = j + k < n ? rank[j + k] : -1;
            return ri < rj;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; ++i) {
            tmp[sa[i]] = tmp[sa[i-1]] + (cmp(sa[i-1], sa[i]) ? 1 : 0);
        }
        rank = tmp;
        if (rank[sa[n-1]] == n-1) break;
    }
    return sa;
}

int main() {
    int n = 7;
    vector<int> sa = {3,2,0,1,5,6,4};
    vector<int> rank(n);
    for (int i = 0; i < n; ++i) rank[sa[i]] = i;
    vector<int> nxt(n);
    for (int i = 0; i < n-1; ++i) nxt[i] = rank[i+1];
    nxt[n-1] = -1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = nxt[sa[i]];
    cout << "a: "; for (int x : a) cout << x << " "; cout << "\n";
    
    vector<int> tails, pile_idx(n);
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        auto it = lower_bound(tails.begin(), tails.end(), x, greater<int>());
        int idx = it - tails.begin();
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
        pile_idx[i] = idx + 1;
    }
    cout << "piles: "; for (int x : pile_idx) cout << x << " "; cout << "\n";
    cout << "max_char: " << tails.size() << "\n";
    
    vector<int> char_at(n);
    for (int i = 0; i < n; ++i) char_at[sa[i]] = pile_idx[i];
    string s;
    for (int i = 0; i < n; ++i) s.push_back('a' + char_at[i] - 1);
    cout << "s: " << s << "\n";
    
    vector<int> computed_sa = build_sa(s);
    cout << "computed SA: "; for (int x : computed_sa) cout << x << " "; cout << "\n";
    cout << "expected SA: "; for (int x : sa) cout << x << " "; cout << "\n";
    cout << "match: " << (computed_sa == sa) << "\n";
    return 0;
}
