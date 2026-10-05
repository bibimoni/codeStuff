#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        long long p = 1;
        bool stan = true;
        while (p < n) {
            if (stan) p *= 9;
            else p *= 2;
            stan = !stan;
        }
        // stan is now the player who would move next, so the previous player won
        stan = !stan;
        if (stan) cout << "La premiere joueuse gagne.\n";
        else cout << "La deuxieme joueuse gagne.\n";
    }
    return 0;
}