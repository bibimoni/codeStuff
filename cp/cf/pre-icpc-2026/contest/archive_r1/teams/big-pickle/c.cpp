#include <bits/stdc++.h>
using namespace std;
static int H;  // number of levels
static int ask(char c) {
    printf("? %c\n", c);
    fflush(stdout);
    int r;
    if (scanf("%d", &r) != 1 || (r != 0 && r != 1)) exit(0);
    return r;
}
// At a node on level lv whose subtree contains at least one existing node on level H.
// Returns the 0-based offset (within this node's range of level-H indices) of the last one.
static long long solve(int lv) {
    if (lv == H) return 0;
    long long L = 1LL << (H - lv - 1);
    if (ask('R')) {
        if (lv + 1 == H) return L;
        int t = 0;
        bool ne = true;
        while (lv + 1 + t < H) {
            if (!ask('L')) { ne = false; break; }
            t++;
        }
        for (int i = 0; i < t; i++) ask('B');
        if (ne) return L + solve(lv + 1);
        ask('B');
        ask('L');
        return solve(lv + 1);
    }
    ask('L');
    return solve(lv + 1);
}
int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int h = 1;
        while (ask('L')) h++;
        H = h;
        for (int i = 0; i < h - 1; i++) ask('B');
        long long N = (1LL << (h - 1)) + solve(1);
        printf("! %lld\n", N);
        fflush(stdout);
    }
    return 0;
}
