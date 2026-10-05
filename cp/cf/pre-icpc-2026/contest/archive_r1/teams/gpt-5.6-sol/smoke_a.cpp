#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n), rank(n + 2, 0);
    for (int &x : p) cin >> x;
    for (int i = 0; i < n; ++i) rank[p[i]] = i + 1;

    int answer = 1;
    for (int i = 0; i + 1 < n; ++i)
        answer += rank[p[i] + 1] > rank[p[i + 1] + 1];
    cout << answer << '\n';
}
