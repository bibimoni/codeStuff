#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        // Determine winner using interval formula:
        // Second player wins if n = 1, or if n in [a_k, b_k]
        // where a_k = 9*18^(k-1) + 1, b_k = 18^k for k >= 1
        // First player wins otherwise
        
        bool second_wins = false;
        
        if (n == 1) {
            second_wins = true;
        } else {
            // Find k such that 18^(k-1) < n <= 18^k
            long long pk_prev = 1;  // 18^(k-1)
            long long pk_curr = 18; // 18^k
            int k = 1;
            
            while (pk_curr < n) {
                pk_prev *= 18;
                pk_curr *= 18;
                k++;
            }
            // Now: 18^(k-1) = pk_prev < n <= 18^k = pk_curr
            
            // a_k = 9 * 18^(k-1) + 1 = 9 * pk_prev + 1
            long long a_k = 9 * pk_prev + 1;
            second_wins = (n >= a_k);
        }
        
        if (second_wins) {
            cout << "La deuxieme joueuse gagne." << "\n";
        } else {
            cout << "La premiere joueuse gagne." << "\n";
        }
    }
    
    return 0;
}
