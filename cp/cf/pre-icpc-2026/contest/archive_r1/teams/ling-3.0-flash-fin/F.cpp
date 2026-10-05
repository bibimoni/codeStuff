#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<string> names(n);
    vector<int> h(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        char s[20];
        scanf("%s %d", s, &h[i]);
        names[i] = s;
        cnt[h[i]]++;
    }
    int target = -1;
    for (auto& [hh, c] : cnt) {
        if (c == 7) target = hh;
    }
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        if (h[i] == target) ans.push_back(names[i]);
    }
    for (auto& s : ans) printf("%s\n", s.c_str());
    return 0;
}
