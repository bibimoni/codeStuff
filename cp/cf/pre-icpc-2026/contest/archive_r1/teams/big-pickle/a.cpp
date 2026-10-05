#include <bits/stdc++.h>
using namespace std;
int n, p[55], rk[55];
int main() {
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 1; i <= n; i++) { if (scanf("%d", &p[i]) != 1) return 0; rk[p[i]] = i; }
    rk[n + 1] = 0;
    int ans = 1;
    for (int i = 1; i < n; i++)
        if (rk[p[i] + 1] > rk[p[i + 1] + 1]) ans++;
    printf("%d\n", ans);
    return 0;
}
