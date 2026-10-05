#include <bits/stdc++.h>
using namespace std;
// Interactive: complete binary tree, find N with <= 8000 queries
static char cur[64];
static int curlen = 0;
static int qcount = 0;
static int ask(char c) {
    printf("? %c\n", c);
    fflush(stdout);
    qcount++;
    int r = 0;
    if (scanf("%d", &r) != 1) exit(0);
    return r;
}
// move along path to target (string t of length L); returns whether the final node exists
static int gotoPath(const char *t, int L) {
    int l = 0;
    while (l < curlen && l < L && cur[l] == t[l]) l++;
    // climb
    while ((int)curlen > l) {
        curlen--;
        if (!ask('B')) return 0;
    }
    // descend
    for (int i = l; i < L; i++) {
        cur[curlen] = t[i];
        int r = ask(cur[curlen] == 'L' ? 'L' : 'R');
        if (!r) { curlen = i; return 0; }
        curlen = i + 1;
    }
    return 1;
}
int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    char path[64];
    while (T--) {
        curlen = 0; qcount = 0;
        // phase 1: largest L such that the leftmost node of level L exists
        int lo = 0, hi = 60;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            for (int i = 0; i < mid; i++) path[i] = 'L';
            if (gotoPath(path, mid)) lo = mid;
            else hi = mid - 1;
        }
        int h = lo;
        // phase 2: binary search m in [1, 2^h]
        unsigned long long mlo = 1, mhi = (h == 0) ? 1ULL : (1ULL << h);
        while (mlo < mhi) {
            unsigned long long mid = mlo + (mhi - mlo + 1) / 2;
            unsigned long long idx = mid - 1;
            for (int i = h - 1; i >= 0; i--) path[h - 1 - i] = ((idx >> i) & 1ULL) ? 'R' : 'L';
            if (gotoPath(path, h)) mlo = mid;
            else mhi = mid - 1;
        }
        unsigned long long m = mlo;
        unsigned long long N = ((1ULL << h) - 1) + m;
        printf("! %llu\n", N);
        fflush(stdout);
    }
    return 0;
}
