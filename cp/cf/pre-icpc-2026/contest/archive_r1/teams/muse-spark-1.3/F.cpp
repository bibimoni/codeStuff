#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<string> s(n);
    vector<int> h(n);
    map<int,int> cnt;
    for (int i = 0; i < n; i++) { cin >> s[i] >> h[i]; cnt[h[i]]++; }
    int target = -1;
    for (auto &p : cnt) if (p.second == 7) target = p.first;
    for (int i = 0; i < n; i++) if (h[i] == target) cout << s[i] << "\n";
    return 0;
}
