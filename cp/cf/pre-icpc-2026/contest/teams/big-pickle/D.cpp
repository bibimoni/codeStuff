// D - Duel of the Twin Sisters
// losing positions: 9*18^{i-1} < n <= 18^i
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        long long p = 18;
        while (p < n) p *= 18;
        long long lo = 9 * (p / 18);
        bool lose = (n > lo);
        cout << (lose ? "La deuxieme joueuse gagne." : "La premiere joueuse gagne.") << "\n";
    }
}
