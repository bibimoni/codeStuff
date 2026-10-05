#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int p[55], rk[55];

bool cmp_sa(int a, int b, const char* s) {
    for (int l = 0; l < n; l++) {
        char ca = (a+l < n) ? s[a+l] : 0;
        char cb = (b+l < n) ? s[b+l] : 0;
        if (ca != cb) return ca < cb;
    }
    return true;
}

bool check(const char* s) {
    int sa[55];
    for (int i = 0; i < n; i++) sa[i] = i;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n-i-1; j++)
            if (!cmp_sa(sa[j], sa[j+1], s)) { int t=sa[j]; sa[j]=sa[j+1]; sa[j+1]=t; }
    for (int i = 0; i < n; i++) if (sa[i] != p[i]) return false;
    return true;
}

bool cmp_sa(int a, int b, const char* s) {
    for (int l = 0; l < n; l++) {
        char ca = (a+l < n) ? s[a+l] : 0;
        char cb = (b+l < n) ? s[b+l] : 0;
        if (ca != cb) return ca < cb;
    }
    return true;
}

bool found;
char s[55];
int k;

// Check if assigning s[pos-1] is consistent with the SA
// Only check pairs involving position pos-1 with previously assigned positions
bool consistent(int pos) {
    int a = pos - 1; // the newly assigned position
    for (int b = 0; b < a; b++) {
        if (rk[a] < rk[b]) {
            // suffix(a) < suffix(b)
            if (s[a] > s[b]) return false;
            if (s[a] == s[b]) {
                if (b+1 >= n) return false; // suffix(b+1) empty, suffix(a+1) non-empty => suffix(a+1) > empty => rk[a+1] > rk[b+1]
                if (a+1 < n && rk[a+1] > rk[b+1]) return false;
            }
        } else if (rk[a] > rk[b]) {
            // suffix(a) > suffix(b)
            if (s[a] < s[b]) return false;
            if (s[a] == s[b]) {
                if (a+1 >= n) return false; // suffix(a) is empty, suffix(b) non-empty => empty < non-empty => rk[a] < rk[b]. Contradicts rk[a] > rk[b]
                if (b+1 < n && rk[a+1] < rk[b+1]) return false;
            }
        }
    }
    return true;
}

void gen(int pos) {
    if (found) return;
    if (pos == n) {
        if (check(s)) found = true;
        return;
    }
    for (int c = 0; c < k; c++) {
        s[pos] = c;
        if (consistent(pos+1)) gen(pos+1);
        if (found) return;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { int x; scanf("%d", &x); p[i] = x-1; rk[p[i]] = i; }
    
    for (k = 1; k <= n; k++) {
        found = false;
        memset(s, 0, sizeof(s));
        gen(0);
        if (found) { printf("%d\n", k); return 0; }
    }
    printf("-1\n");
    return 0;
}
