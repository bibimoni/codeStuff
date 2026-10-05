#include <cstdio>

char names[100][11];
int heights[100];
int freq[1001];

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; ++i) {
        scanf("%10s %d", names[i], &heights[i]);
        ++freq[heights[i]];
    }
    int target_h = -1;
    for (int h = 1; h <= 1000; ++h) {
        if (freq[h] == 7) {
            target_h = h;
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (heights[i] == target_h) {
            printf("%s\n", names[i]);
        }
    }
    return 0;
}