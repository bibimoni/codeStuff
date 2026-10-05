// tempting bug: forget the central cell -> 3n(n-1)
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        long long n; scanf("%lld", &n);
        printf("%lld\n", 3 * n * (n - 1));
    }
    return 0;
}
