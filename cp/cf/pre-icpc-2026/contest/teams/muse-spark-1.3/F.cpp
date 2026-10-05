#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<string> S(n);
    vector<int> H(n);
    for (int i = 0; i < n; i++) cin >> S[i] >> H[i];
    unordered_map<int,int> cnt;
    for (int h : H) cnt[h]++;
    int target = -1;
    for (auto &p : cnt) if (p.second == 7) target = p.first;
    for (int i = 0; i < n; i++) if (H[i] == target) cout << S[i] << "\n";
    return 0;
}
