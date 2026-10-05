#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, bound = 1;
        bool first = true;
        cin >> n;
        if (n == 1) {
            cout << "La premiere joueuse gagne.\n";
            continue;
        }
        while (bound < n) {
            bound *= first ? 9 : 2;
            first = !first;
        }
        cout << (first ? "La deuxieme joueuse gagne.\n" : "La premiere joueuse gagne.\n");
    }
}
