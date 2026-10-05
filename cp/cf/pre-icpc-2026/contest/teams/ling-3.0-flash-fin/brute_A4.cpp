#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int p[55]; // 0-indexed target suffix array

// Check if string s has the given suffix array
bool check(const char* s) {
    int sa[55];
    for (int i = 0; i < n; i++) sa[i] = i;
    // Sort by suffix
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
    for (int i = 0; i < n; i++) if (sa[i] != p[i]) return false;
    return true;
}

bool found;
char s[55];
int k;

void gen(int pos, int used) {
    if (found) return;
    if (pos == n) {
        if (check(s)) found = true;
        return;
    }
    for (int c = 0; c < k; c++) {
        s[pos] = c;
        gen(pos+1, used | (1<<c));
        if (found) return;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { int x; scanf("%d", &x); p[i] = x-1; }
    
    for (k = 1; k <= n; k++) {
        found = false;
        gen(0, 0);
        if (found) { printf("%d\n", k); return 0; }
    }
    printf("-1\n");
    return 0;
}
