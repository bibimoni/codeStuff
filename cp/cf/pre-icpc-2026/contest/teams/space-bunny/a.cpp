#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; scanf("%d", &n);
    vector<int> p(n), rk(n + 1);
    for (int i = 0; i < n; i++) { scanf("%d", &p[i]); p[i]--; rk[p[i]] = i; }
    rk[n] = -1;   // empty suffix is smallest
    int ans = 1;
    for (int i = 0; i + 1 < n; i++) {
        // equal chars allowed iff rk[p_i+1] < rk[p_{i+1}+1]
        if (rk[p[i] + 1] > rk[p[i + 1] + 1]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
