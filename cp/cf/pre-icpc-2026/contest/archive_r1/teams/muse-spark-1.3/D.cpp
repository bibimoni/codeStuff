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
        long long a = 1;
        bool first = true;
        while (true) {
            if (first) {
                a *= 9;
                if (n <= a) { cout << "La premiere joueuse gagne.\n"; break; }
                first = false;
            } else {
                a *= 2;
                if (n <= a) { cout << "La deuxieme joueuse gagne.\n"; break; }
                first = true;
            }
        }
    }
    return 0;
}
