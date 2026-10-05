#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> p(n);
        vector<int> pos(n + 2, 0);
        
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            // Store the rank (i + 1) of the suffix starting at p[i]
            pos[p[i]] = i + 1;
        }
        
        // The empty suffix conceptually starts at n + 1 and has rank 0
        pos[n + 1] = 0; 
        
        int min_chars = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (pos[p[i] + 1] > pos[p[i+1] + 1]) {
                min_chars++;
            }
        }
        cout << min_chars << "\n";
    }
    return 0;
}