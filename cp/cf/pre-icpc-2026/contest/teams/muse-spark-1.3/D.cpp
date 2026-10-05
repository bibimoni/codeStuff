#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long n;
        cin >> n;
        if (n <= 1) { cout << "La premiere joueuse gagne.\n"; continue; }
        long long p = 1;
        int turn = 0; // 0 first, 1 second
        while (p < n) {
            if (turn == 0) p *= 9;
            else p *= 2;
            turn ^= 1;
        }
        // last mover = turn^1
        if ((turn ^ 1) == 0) cout << "La premiere joueuse gagne.\n";
        else cout << "La deuxieme joueuse gagne.\n";
    }
    return 0;
}
