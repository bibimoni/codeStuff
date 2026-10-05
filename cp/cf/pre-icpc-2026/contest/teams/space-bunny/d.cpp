#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long n;
        scanf("%lld", &n);
        // T intervals (0,9],(18,162],(324,2916],(5832,52488],(104976,944784],
        // (1889568,17006112],(34012224,306110016],(612220032,5509980288]
        long long lo = 0, hi = 9;
        bool win = (n <= 9);
        while (!win) {
            // F interval (hi, 2*hi], then T (2*hi, 18*hi]
            if (n <= 2 * hi) { win = false; break; }
            long long nlo = 2 * hi, nhi = 18 * hi;
            if (n <= nhi) { win = true; break; }
            hi = nhi;
        }
        if (win) printf("La premiere joueuse gagne.\n");
        else printf("La deuxieme joueuse gagne.\n");
    }
    return 0;
}
