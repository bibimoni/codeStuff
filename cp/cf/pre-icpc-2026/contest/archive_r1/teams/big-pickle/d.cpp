#include <cstdio>
int main() {
    int T; if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        long long n; scanf("%lld", &n);
        long long hi = 9; int st = 1; // 1 = first player wins on [1,9]
        while (hi < n) { hi = hi * (st ? 2 : 9); st = !st; }
        puts(st ? "La premiere joueuse gagne." : "La deuxieme joueuse gagne.");
    }
    return 0;
}
