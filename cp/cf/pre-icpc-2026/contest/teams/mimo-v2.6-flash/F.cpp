#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; scanf("%d", &n);
    vector<string> nm(n); vector<int> h(n);
    map<int,int> cnt;
    for (int i = 0; i < n; i++) { cin >> nm[i] >> h[i]; cnt[h[i]]++; }
    int target = -1;
    for (auto &p : cnt) if (p.second == 7) target = p.first;
    for (int i = 0; i < n; i++) if (h[i] == target) cout << nm[i] << "\n";
    return 0;
}
