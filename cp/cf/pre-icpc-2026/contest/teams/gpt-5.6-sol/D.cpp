#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        long long n, reach = 1;
        cin >> n;
        bool first = true;
        while (reach < n) {
            reach *= first ? 9 : 2;
            if (reach >= n) break;
            first = !first;
        }
        cout << (first ? "La premiere joueuse gagne.\n" : "La deuxieme joueuse gagne.\n");
    }
}
