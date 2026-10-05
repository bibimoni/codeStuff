#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<string, int>> a(n);
    map<int, int> cnt;
    for (auto &[name, height] : a) {
        cin >> name >> height;
        ++cnt[height];
    }
    for (const auto &[name, height] : a)
        if (cnt[height] == 7) cout << name << '\n';
}
