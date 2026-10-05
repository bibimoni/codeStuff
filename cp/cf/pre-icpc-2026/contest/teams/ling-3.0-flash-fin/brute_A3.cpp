#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int target[55]; // 0-indexed target suffix array

bool sa_equals(const char* s) {
    int sa[55];
    for (int i = 0; i < n; i++) sa[i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            bool sai_lt = false;
            for (int l = 0; l < n; l++) {
                char a = (sa[i]+l < n) ? s[sa[i]+l] : 0;
                char b = (sa[j]+l < n) ? s[sa[j]+l] : 0;
                if (a < b) { sai_lt = true; break; }
                if (a > b) { sai_lt = false; break; }
            }
            if (!sai_lt) { int t = sa[i]; sa[i] = sa[j]; sa[j] = t; }
        }
    }
    for (int i = 0; i < n; i++) if (sa[i] != target[i]) return false;
    return true;
}

bool try_k(int k) {
    int total = 1;
    for (int i = 0; i < n; i++) total *= k;
    char s[55];
    for (int mask = 0; mask < total; mask++) {
        int tmp = mask;
        for (int i = 0; i < n; i++) { s[i] = tmp % k; tmp /= k; }
        if (sa_equals(s)) return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { int x; scanf("%d", &x); target[i] = x-1; }
    for (int k = 1; k <= n; k++) {
        if (try_k(k)) { printf("%d\n", k); return 0; }
    }
    printf("-1\n");
    return 0;
}
