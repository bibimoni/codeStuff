#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int p[55], rank_arr[55], n;

int suffix_arr_rank(int pos, const char* s) {
    // Compute rank of suffix starting at pos
    for (int i = 0; i < n; i++) {
        if (p[i] == pos) return i;
    }
    return -1;
}

bool check(const char* s) {
    // Compute suffix array of s
    int sa[55];
    for (int i = 0; i < n; i++) sa[i] = i;
    // Sort by suffix
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            // Compare suffix starting at sa[i] vs sa[j]
            bool swap_flag = false;
            for (int k = 0; k < n; k++) {
                char a = (sa[i]+k < n) ? s[sa[i]+k] : 0;
                char b = (sa[j]+k < n) ? s[sa[j]+k] : 0;
                if (a < b) { swap_flag = true; break; }
                if (a > b) { swap_flag = false; break; }
            }
            if (swap_flag) { int t = sa[i]; sa[i] = sa[j]; sa[j] = t; }
        }
    }
    for (int i = 0; i < n; i++) if (sa[i] != p[i]-1) return false;
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    for (int i = 0; i < n; i++) p[i]--; // 0-indexed
    
    // Brute force: try k = 1, 2, ... characters
    for (int k = 1; k <= n; k++) {
        // Try all strings with characters 0..k-1
        char s[55];
        int total = 1;
        for (int i = 0; i < n; i++) total *= k;
        bool found = false;
        for (int mask = 0; mask < total && !found; mask++) {
            int tmp = mask;
            for (int i = 0; i < n; i++) { s[i] = tmp % k; tmp /= k; }
            // Check suffix array
            int sa[55];
            for (int i = 0; i < n; i++) sa[i] = i;
            // Bubble sort by suffix
            for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                    bool sw = false;
                    for (int l = 0; l < n; l++) {
                        char a = (sa[i]+l < n) ? s[sa[i]+l] : 0;
                        char b = (sa[j]+l < n) ? s[sa[j]+l] : 0;
                        if (a < b) { sw = true; break; }
                        if (a > b) { sw = false; break; }
                    }
                    if (sw) { int t = sa[i]; sa[i] = sa[j]; sa[j] = t; }
                }
            }
            bool match = true;
            for (int i = 0; i < n; i++) if (sa[i] != p[i]) { match = false; break; }
            if (match) found = true;
        }
        if (found) { printf("%d\n", k); return 0; }
    }
    printf("-1\n");
    return 0;
}
