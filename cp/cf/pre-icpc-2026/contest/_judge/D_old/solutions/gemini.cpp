#include <iostream>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long p = 1;
    
    // Simulate the alternating optimal moves
    while (true) {
        p *= 9;
        if (p >= n) {
            cout << "La premiere joueuse gagne.\n";
            break;
        }
        
        p *= 2;
        if (p >= n) {
            cout << "La deuxieme joueuse gagne.\n";
            break;
        }
    }
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}