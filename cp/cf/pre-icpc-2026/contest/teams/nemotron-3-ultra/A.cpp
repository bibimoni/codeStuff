#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> p(n+1), rank(n+2);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        rank[p[i]] = i;
    }
    rank[n+1] = 0; // empty suffix
    
    int strict = 0;
    for (int i = 1; i < n; ++i) {
        int a = p[i], b = p[i+1];
        if (rank[a+1] > rank[b+1]) strict++;
    }
    cout << strict + 1 << '\n';
    return 0;
}