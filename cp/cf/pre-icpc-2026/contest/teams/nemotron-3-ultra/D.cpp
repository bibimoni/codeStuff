#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    vector<long long> thresh = {1};
    long long p = 1;
    int turn = 0; // 0 = first (maximize), 1 = second (minimize)
    while (p <= 1e18) {
        if (turn == 0) p *= 9;
        else p *= 2;
        thresh.push_back(p);
        turn ^= 1;
    }
    
    while (T--) {
        long long n;
        cin >> n;
        if (n <= 1) {
            cout << "La premiere joueuse gagne.\n";
            continue;
        }
        bool first_wins = false;
        for (size_t i = 1; i + 1 < thresh.size(); i += 2) {
            if (n > thresh[i-1] && n <= thresh[i]) {
                first_wins = true;
                break;
            }
        }
        if (first_wins) {
            cout << "La premiere joueuse gagne.\n";
        } else {
            cout << "La deuxieme joueuse gagne.\n";
        }
    }
    return 0;
}