#include <cstdio>
#include <cstring>

int main() {
    int n, h[100], count[1001] = {};
    char name[100][11];
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; ++i) {
        scanf("%10s%d", name[i], &h[i]);
        ++count[h[i]];
    }
    for (int i = 0; i < n; ++i)
        if (count[h[i]] == 7) puts(name[i]);
}
