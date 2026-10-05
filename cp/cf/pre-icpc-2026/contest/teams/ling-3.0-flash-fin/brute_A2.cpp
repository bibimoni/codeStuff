#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
// Brute force: for each k, try all k^n strings and check SA
int n;
int p[55]; // 0-indexed target suffix array

bool sa_equals(const char* s) {
    int sa[55];
    for (int i = 0; i < n; i++) sa[i] = i;
    // Sort by suffix using comparison
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            // Compare suffix at sa[i] vs sa[j]
            bool sai_lt_saj = false;
            for (int l = 0; l < n; l++) {
                char a = (sa[i]+l < n) ? s[sa[i]+l] : 0;
                char b = (sa[j]+l < n) ? s[sa[j]+l] : 0;
                if (a < b) { sai_lt_saj = true; break; }
                if (a > b) { sai_lt_saj = false; break; }
            }
            if (!sai_lt_saj) {
                // sai >= saj, swap
                int t = sa[i]; sa[i] = sa[j]; sa[j] = t;
            }
        }
    }
    for (int i = 0; i < n; i++) if (sa[i] != p[i]) return false;
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x); x--; p[i] = x; // 0-indexed
    }
    
    for (int k = 1; k <= n; k++) {
        int total = 1;
        for (int i = 0; i < n; i++) total *= k;
        bool found = false;
        char s[55];
        for (int mask = 0; mask < total && !found; mask++) {
            int tmp = mask;
            for (int i = 0; i < n; i++) { s[i] = tmp % k; tmp /= k; }
            if (sa_equals(s)) found = true;
        }
        if (found) { printf("k=%d\n", k); return 0; }
    }
    printf("k=-1\n");
    return 0;
}
