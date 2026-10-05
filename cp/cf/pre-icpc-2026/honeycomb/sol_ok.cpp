// equivalent O(t) via summing ring sizes 6,12,...,6(n-1) with int64
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        long long n; scanf("%lld", &n);
        long long k = n - 1, ans = 1 + 3 * k * (k + 1);
        printf("%lld\n", ans);
    }
    return 0;
}
