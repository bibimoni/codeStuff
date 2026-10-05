#include <cstdio>
#include <cstring>
int main() {
    int n;
    scanf("%d", &n);
    int h[101];
    char nm[101][12];
    for (int i = 0; i < n; i++) {
        scanf("%s %d", nm[i], &h[i]);
    }
    int cnt[1001] = {};
    for (int i = 0; i < n; i++) cnt[h[i]]++;
    int target = -1;
    for (int i = 0; i < n; i++) {
        if (cnt[h[i]] == 7) { target = h[i]; break; }
    }
    for (int i = 0; i < n; i++) {
        if (h[i] == target) {
            puts(nm[i]);
        }
    }
    return 0;
}
