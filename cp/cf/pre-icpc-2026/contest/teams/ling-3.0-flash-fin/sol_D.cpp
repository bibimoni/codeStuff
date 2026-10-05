#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long n;
        scanf("%lld", &n);
        bool first_wins = false;
        long long bound = n;
        while (true) {
            long long N_lo = (bound + 8) / 9;
            if (N_lo <= 1) { first_wins = true; break; }
            long long P_lo = (N_lo + 1) / 2;
            if (P_lo <= 1) { first_wins = false; break; }
            bound = P_lo;
        }
        puts(first_wins ? "La premiere joueuse gagne." : "La deuxieme joueuse gagne.");
    }
    return 0;
}
