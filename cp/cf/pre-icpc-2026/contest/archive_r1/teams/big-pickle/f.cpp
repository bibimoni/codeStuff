#include <cstdio>
int cnt[1001], hh[101];
char nm[101][16];
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        int h;
        if (scanf("%15s %d", nm[i], &h) != 2) return 0;
        hh[i] = h;
        cnt[h]++;
    }
    int best = -1;
    for (int h = 1; h <= 1000; h++)
        if (cnt[h] == 7) { best = h; break; }
    for (int i = 0; i < n; i++)
        if (hh[i] == best) printf("%s\n", nm[i]);
    return 0;
}
