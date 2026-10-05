#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long n;
        scanf("%lld", &n);
        if (n <= 9) {
            printf("La premiere joueuse gagne.\n");
        } else {
            long long p = 18;
            while (p < n) p *= 18;
            if (n > p / 2) {
                printf("La deuxieme joueuse gagne.\n");
            } else {
                printf("La premiere joueuse gagne.\n");
            }
        }
    }
    return 0;
}
