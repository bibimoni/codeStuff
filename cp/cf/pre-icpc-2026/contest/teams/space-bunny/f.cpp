#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, string>> v;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        char s[32];
        int h;
        scanf("%s %d", s, &h);
        v.push_back({h, s});
        cnt[h]++;
    }
    int best = -1, bc = 0;
    for (auto &kv : cnt) if (kv.second > bc) { bc = kv.second; best = kv.first; }
    for (auto &p : v) if (p.first == best) printf("%s\n", p.second.c_str());
    return 0;
}
