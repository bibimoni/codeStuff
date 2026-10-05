// F - Fairest of Them All
#include <cstdio>
#include <string>
using namespace std;
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    static char name[105][16];
    static int h[105];
    int cnt[1001];
    for (int i = 1; i <= 1000; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) scanf("%15s %d", name[i], &h[i]), cnt[h[i]]++;
    int good = -1;
    for (int i = 1; i <= 1000; i++) if (cnt[i] == 7) { good = i; break; }
    for (int i = 0; i < n; i++)
        if (h[i] == good) printf("%s\n", name[i]);
    return 0;
}
